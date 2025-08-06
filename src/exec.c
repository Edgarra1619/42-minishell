#include <minishell/fd.h>
#include <minishell/path.h>
#include <minishell/env.h>
#include <minishell/builtins.h>
#include <minishell/error.h>
#include <libft.h>

#include <stdlib.h>
#include <stdbool.h>

static bool	is_command_builtin(const char *const cmd);
static int	exec_builtin(t_cmd *const cmd);
static void	exec_binary(t_cmd *const cmd);

int	exec_command(t_cmd *const cmd)
{
	const bool	is_builtin = is_command_builtin(cmd->argv[0]);
	int			i;

	cmd->pid = fork();
	if (cmd->pid == -1)
		return (print_error(*cmd->argv, NULL, NULL));
	close_fd(&cmd->pipe[!!cmd->pid]);
	if (cmd->pid > 0)
	{
		if (is_builtin)
			exec_builtin(cmd);
		return (0);
	}
	i = -1;
	while (cmd->redirs[++i].source_fd >= 0)
		if (redirect_fd(&cmd->redirs[i]))
			exit(print_error(*cmd->argv, cmd->redirs[i].target_path, NULL));
	if (is_builtin)
		exit(exec_builtin(cmd));
	exec_binary(cmd);
	exit(0);
}

static int	exec_builtin(t_cmd *const cmd)
{
	const bool	print_output = !cmd->pid;

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

static void	exec_binary(t_cmd *const cmd)
{
	char	**envp;

	if (resolve_binary_path(*cmd->argv, cmd->path))
	{
		if (ft_strchr(*cmd->argv, '/'))
			exit(print_error(*cmd->argv, NULL, NULL));
		exit(print_error(*cmd->argv, NULL, "command not found"));
	}
	get_env(NULL, NULL, &envp);
	execve(cmd->path, cmd->argv, envp);
	exit(print_error(*cmd->argv, NULL, NULL));
}

static bool	is_command_builtin(const char *const cmd)
{
	return (!ft_strcmp(cmd, "cd")
		|| !ft_strcmp(cmd, "export")
		|| !ft_strcmp(cmd, "unset")
		|| !ft_strcmp(cmd, "echo")
		|| !ft_strcmp(cmd, "env")
		|| !ft_strcmp(cmd, "pwd"));
}
