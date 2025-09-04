#include <minishell/env.h>
#include <minishell/pipeline.h>
#include <minishell/cmd.h>
#include <minishell/fd.h>
#include <minishell/path.h>
#include <minishell/builtins.h>
#include <minishell/error.h>
#include <libft.h>

#include <stdlib.h>
#include <unistd.h>

static void	exec_cmd(t_cmd *const cmd, const bool is_single_cmd);
static int	exec_builtin(t_cmd *const cmd);
static int	exec_binary(t_cmd *const cmd);

void	exec_pipeline(t_pipeline *const pl)
{
	int		i;
	t_cmd	*cmd;

	i = -1;
	while (++i < pl->num_cmds)
	{
		cmd = pl->cmds + i;
		if (i + 1 < pl->num_cmds)
			pipe_cmds(cmd, cmd + 1);
		exec_cmd(cmd, pl->num_cmds == 1);
	}
	close_unused_fds(NULL);
}

static void	exec_cmd(t_cmd *const cmd, const bool is_single_cmd)
{
	const bool	is_builtin = !cmd->argv[0] || is_cmd_builtin(cmd->argv[0]);
	int			ret;

	fork_cmd(cmd);
	if (cmd->pid > 0)
	{
		if (is_single_cmd && is_builtin)
			exec_builtin(cmd);
		return ;
	}
	if (is_builtin)
		ret = exec_builtin(cmd);
	else
		ret = exec_binary(cmd);
	clear_pipeline(NULL);
	exit(ret);
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

	if (resolve_binary_path(cmd->argv[0], cmd->path))
	{
		if (ft_strchr(*cmd->argv, '/'))
			return (print_error(*cmd->argv, NULL, NULL));
		return (print_error(*cmd->argv, NULL, "command not found"));
	}
	get_env(NULL, NULL, &envp, NULL);
	execve(cmd->path, cmd->argv, envp);
	return (print_error(*cmd->argv, NULL, NULL));
}
