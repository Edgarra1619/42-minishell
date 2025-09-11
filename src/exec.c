#include <minishell/env.h>
#include <minishell/pipeline.h>
#include <minishell/cmd.h>
#include <minishell/fd.h>
#include <minishell/path.h>
#include <minishell/builtins.h>
#include <minishell/error.h>
#include <minishell/signals.h>
#include <minishell/exit.h>
#include <libft.h>

#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>

static void	exec_cmd(t_cmd *cmd, bool is_single_cmd);
static int	exec_builtin(t_cmd *cmd, bool is_single_cmd);
static int	exec_binary(t_cmd *cmd);

void	exec_pipeline(t_pipeline *const pl)
{
	const bool	is_single_cmd = pl->num_cmds == 1;
	int			i;
	t_cmd		*cmd;

	if (!is_single_cmd)
		update_shlvl(-1, true);
	i = -1;
	while (++i < pl->num_cmds)
	{
		cmd = pl->cmds + i;
		if (i + 1 < pl->num_cmds)
			pipe_cmds(cmd, cmd + 1);
		exec_cmd(cmd, is_single_cmd);
	}
	close_unused_fds(NULL);
	if (!is_single_cmd)
		update_shlvl(1, true);
}

static void	exec_cmd(t_cmd *const cmd, const bool is_single_cmd)
{
	const bool	is_builtin = !cmd->argv[0] || is_cmd_builtin(cmd->argv[0]);
	int			ret;

	fork_cmd(cmd);
	if (cmd->pid > 0)
	{
		if (is_single_cmd && is_builtin)
			exec_builtin(cmd, is_single_cmd);
		return ;
	}
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	if (is_builtin)
		ret = exec_builtin(cmd, is_single_cmd);
	else
		ret = exec_binary(cmd);
	clear_exit(ret);
}

static int	exec_builtin(t_cmd *const cmd, const bool is_single_cmd)
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
		return (exit_builtin(cmd->argv, print_output, is_single_cmd));
	if (!print_output)
		return (0);
	if (!ft_strcmp(name, "echo"))
		return (echo_builtin(cmd->argv));
	if (!ft_strcmp(name, "env"))
		return (env_builtin());
	print_error(name, NULL, "builtin not found");
	return (1);
}

static int	exec_binary(t_cmd *const cmd)
{
	char	**envp;

	if (resolve_binary_path(cmd->argv[0], cmd->path))
	{
		if (!ft_strchr(*cmd->argv, '/'))
		{
			print_error(*cmd->argv, NULL, "command not found");
			return (get_error_status());
		}
		print_error(*cmd->argv, NULL, NULL);
		return (get_error_status());
	}
	remove_uninitialized_vars();
	get_env(NULL, NULL, &envp, NULL);
	execve(cmd->path, cmd->argv, envp);
	print_error(*cmd->argv, NULL, NULL);
	return (get_error_status());
}
