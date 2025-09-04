#include <minishell/fd.h>
#include <minishell/path.h>
#include <minishell/env.h>
#include <minishell/builtins.h>
#include <minishell/tokenizer.h>
#include <minishell/error.h>
#include <minishell/signals.h>
#include <libft.h>

#include <signal.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

static int	pipe_cmds(t_cmd *const cmd1, t_cmd *const cmd2);
static int	exec_cmd(t_cmd *const cmd, const bool is_single_cmd);
static bool	is_cmd_builtin(const char *const name);
static int	exec_builtin(t_cmd *const cmd);
static int	exec_binary(t_cmd *const cmd);

int	exec_pipeline(t_pipeline *const pl)
{
	int		i;
	t_cmd	*cmd;

	i = -1;
	while (++i < pl->num_cmds)
	{
		cmd = pl->cmds + i;
		if (i + 1 < pl->num_cmds)
			pipe_cmds(cmd, cmd + 1);
		tokenize_cmd(cmd);
		exec_cmd(cmd, pl->num_cmds == 1);
	}
	close_unused_fds(NULL);
	return (0);
}

void	wait_pipeline(t_pipeline *const pl)
{
	int		i;
	char	*status;

	get_env(NULL, NULL, NULL, &status);
	i = 0;
	while (i < pl->num_cmds && pl->cmds[i].pid > 0)
	{
		waitpid(pl->cmds[i].pid, &pl->cmds[i].status, 0);
		*status = WEXITSTATUS(pl->cmds[i].status);
		i++;
	}
}

static int	exec_cmd(t_cmd *const cmd, const bool is_single_cmd)
{
	const bool	is_builtin = is_cmd_builtin(cmd->argv[0]);
	int			i;

	cmd->pid = fork();
	if (cmd->pid == -1)
		return (print_error(*cmd->argv, NULL, NULL));
	if (cmd->pid > 0)
	{
		if (!is_single_cmd)
			return (0);
		if (!ft_strcmp(cmd->argv[0], "exit"))
			exit(exec_builtin(cmd));
		if (is_builtin)
			exec_builtin(cmd);
		return (0);
	}
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	i = -1;
	while (++i < cmd->num_redirs)
		if (redirect_fd(&cmd->redirs[i]))
			exit(print_error(*cmd->argv, cmd->redirs[i].target_path, NULL));
	close_unused_fds(cmd);
	if (is_builtin)
		exit(exec_builtin(cmd));
	exit(exec_binary(cmd));
}

static int	exec_builtin(t_cmd *const cmd)
{
	const char *const	name = cmd->argv[0];
	const bool			print_output = !cmd->pid;

	if (!name || !ft_strcmp(name, "true"))
		return (0);
	if (!ft_strcmp(name, "false"))
		return (1);
	if (!ft_strcmp(name, "cd"))
		return (cd_builtin(cmd->argv, print_output));
	if (!ft_strcmp(name, "pwd"))
		return (pwd_builtin(print_output));
	if (!ft_strcmp(name, "export"))
		return (export_builtin(cmd->argv, print_output));
	if (!ft_strcmp(name, "unset"))
		return (unset_builtin(cmd->argv));
	if (!ft_strcmp(name, "exit"))
		return (exit_builtin(cmd->argv, print_output));
	if (!print_output)
		return (0);
	if (!ft_strcmp(name, "echo"))
		return (echo_builtin(cmd->argv));
	if (!ft_strcmp(name, "env"))
		return (env_builtin());
	return (print_error(name, NULL, "builtin not found"));
}

static int	exec_binary(t_cmd *const cmd)
{
	char	**envp;

	if (resolve_binary_path(*cmd->argv, cmd->path))
	{
		if (ft_strchr(*cmd->argv, '/'))
			exit(print_error(*cmd->argv, NULL, NULL));
		exit(print_error(*cmd->argv, NULL, "command not found"));
	}
	get_env(NULL, NULL, &envp, NULL);
	execve(cmd->path, cmd->argv, envp);
	return (print_error(*cmd->argv, NULL, NULL));
}

static int	pipe_cmds(t_cmd *const cmd1, t_cmd *const cmd2)
{
	int	fds[2];

	if (pipe(fds))
		return (1);
	cmd1->redirs[cmd1->num_redirs++] = (t_redir){1, fds[1], NULL, 0};
	cmd2->redirs[cmd2->num_redirs++] = (t_redir){0, fds[0], NULL, 0};
	return (0);
}

static bool	is_cmd_builtin(const char *const name)
{
	return (!ft_strcmp(name, "true")
		|| !ft_strcmp(name, "false")
		|| !ft_strcmp(name, "cd")
		|| !ft_strcmp(name, "export")
		|| !ft_strcmp(name, "unset")
		|| !ft_strcmp(name, "echo")
		|| !ft_strcmp(name, "env")
		|| !ft_strcmp(name, "pwd")
		|| !ft_strcmp(name, "exit"));
}
