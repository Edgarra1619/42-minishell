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
#include <libft.h>

#include <readline/readline.h>
#include <fcntl.h>
#include <unistd.h>

int	g_lastsignal;

void	heredoc_handler(int sig)
{
	ft_putchar_fd('\n', 2);
	close(0);
	g_lastsignal = sig;
}

void	prompt_handler(int sig)
{
	rl_replace_line("", 1);
	ft_putchar_fd('\n', 2);
	rl_on_new_line();
	rl_redisplay();
	g_lastsignal = sig;
}
