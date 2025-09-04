#include <minishell/types.h>
#include <minishell/pipeline.h>
#include <minishell/fd.h>
#include <minishell/error.h>
#include <libft.h>

#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

void	fork_cmd(t_cmd *const cmd)
{
	int	i;

	cmd->pid = fork();
	if (cmd->pid == -1)
		error_exit();
	if (cmd->pid > 0)
		return ;
	i = -1;
	while (++i < cmd->num_redirs)
	{
		if (redirect_fd(&cmd->redirs[i]))
		{
			clear_pipeline(NULL);
			exit(print_error(NULL, cmd->redirs[i].target_path, NULL));
		}
	}
	close_unused_fds(cmd);
}

void	pipe_cmds(t_cmd *const cmd1, t_cmd *const cmd2)
{
	int	fds[2];

	if (pipe(fds))
		error_exit();
	cmd1->redirs[cmd1->num_redirs++] = (t_redir){1, fds[1], NULL, 0};
	cmd2->redirs[cmd2->num_redirs++] = (t_redir){0, fds[0], NULL, 0};
}

bool	is_cmd_builtin(const char *const name)
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
