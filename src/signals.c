/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgribei <edgribei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:46:24 by edgribei          #+#    #+#             */
/*   Updated: 2025/09/23 14:46:30 by edgribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell/signals.h>
#include <minishell/minishell.h>

#include <readline/readline.h>
#include <fcntl.h>
#include <signal.h>
#include <unistd.h>

int	g_lastsignal;

void	heredoc_handler(int sig)
{
	write(1, "\n", 1);
	close(0);
	g_lastsignal = sig;
}

void	prompt_handler(int sig)
{
	if (sig != SIGINT)
		return ;
	rl_replace_line("", 1);
	write(1, "\n", 1);
	rl_on_new_line();
	rl_redisplay();
}
