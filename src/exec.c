#include <minishell/fd.h>
#include <minishell/path.h>
#include <minishell/env.h>
#include <minishell/builtins.h>
#include <minishell/tokenizer.h>
#include <minishell/error.h>
#include <libft.h>

#include <sys/wait.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

static int	exec_cmd(t_cmd *const cmd);
static bool	is_cmd_builtin(const char *const cmd);
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
		{
			pipe(cmd->pipe);
			cmd->redirs[cmd->num_redirs++]
				= (t_redir){1, cmd->pipe[1], NULL, OPEN_PIPE_WRITE};
			cmd[1].redirs[cmd[1].num_redirs++]
				= (t_redir){0, cmd->pipe[0], NULL, OPEN_PIPE_READ};
		}
		tokenize_cmd(cmd);
		exec_cmd(cmd);
		if (i)
			close_fd(cmd[-1].pipe + 0);
		close_fd(cmd->pipe + 1);
	}
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

static int	exec_cmd(t_cmd *const cmd)
{
	const bool	is_builtin = is_cmd_builtin(cmd->argv[0]);
	int			i;

	cmd->pid = fork();
	if (cmd->pid == -1)
		return (print_error(*cmd->argv, NULL, NULL));
	if (cmd->pid > 0)
	{
		if (is_builtin)
			exec_builtin(cmd);
		return (0);
	}
	close_fd(cmd->pipe);
	i = -1;
	while (++i < cmd->num_redirs)
		if (redirect_fd(&cmd->redirs[i]))
			exit(print_error(*cmd->argv, cmd->redirs[i].target_path, NULL));
	if (is_builtin)
		exit(exec_builtin(cmd));
	exit(exec_binary(cmd));
}

static int	exec_builtin(t_cmd *const cmd)
{
	const bool	print_output = !cmd->pid;

	if (!cmd->argv[0] || !ft_strcmp(cmd->argv[0], "true"))
		return (0);
	if (!ft_strcmp(cmd->argv[0], "false"))
		return (1);
	if (!ft_strcmp(cmd->argv[0], "cd"))
		return (cd(cmd->argv, print_output));
	if (!ft_strcmp(cmd->argv[0], "pwd"))
		return (pwd(print_output));
	if (!ft_strcmp(cmd->argv[0], "export"))
		return (export(cmd->argv, print_output));
	if (!ft_strcmp(cmd->argv[0], "unset"))
		return (unset(cmd->argv));
	if (!print_output)
		return (0);
	if (!ft_strcmp(cmd->argv[0], "echo"))
		return (echo(cmd->argv));
	if (!ft_strcmp(cmd->argv[0], "env"))
		return (env());
	return (print_error(*cmd->argv, NULL, "builtin not found"));
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

static bool	is_cmd_builtin(const char *const cmd)
{
	return (!ft_strcmp(cmd, "true")
		|| !ft_strcmp(cmd, "false")
		|| !ft_strcmp(cmd, "cd")
		|| !ft_strcmp(cmd, "export")
		|| !ft_strcmp(cmd, "unset")
		|| !ft_strcmp(cmd, "echo")
		|| !ft_strcmp(cmd, "env")
		|| !ft_strcmp(cmd, "pwd"));
}
