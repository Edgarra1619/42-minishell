/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-albu <vde-albu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:47:35 by vde-albu          #+#    #+#             */
/*   Updated: 2025/09/23 14:47:36 by vde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell/types.h>
#include <minishell/pipeline.h>
#include <minishell/fd.h>
#include <minishell/error.h>
#include <minishell/exit.h>
#include <libft.h>

#include <stdbool.h>
#include <unistd.h>

void	fork_cmd(t_cmd *const cmd)
{
	int	i;

	cmd->pid = fork();
	if (cmd->pid == -1)
		error_exit(1);
	if (cmd->pid > 0)
		return ;
	redirect_fd(cmd->pipes);
	redirect_fd(cmd->pipes + 1);
	i = -1;
	while (++i < cmd->num_redirs)
		redirect_fd(&cmd->redirs[i]);
	close_unused_fds(cmd);
}

void	pipe_cmds(t_cmd *const cmd1, t_cmd *const cmd2)
{
	int	fds[2];

	if (pipe(fds))
		error_exit(1);
	cmd1->pipes[1] = (t_redir){1, fds[1], NULL, 0};
	cmd2->pipes[0] = (t_redir){0, fds[0], NULL, 0};
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
