/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgribei <edgribei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:46:52 by edgribei          #+#    #+#             */
/*   Updated: 2025/09/23 14:46:53 by edgribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell/signals.h>
#include <minishell/env.h>
#include <minishell/tokenizer.h>
#include <minishell/exit.h>
#include <minishell/error.h>

#include <libft.h>

#include <readline/readline.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>

static int	heredoc_parse_line(int fd, char *input, const char *eof);

int	open_heredoc(int *const target_fd, const char *const eof)
{
	const int		stdinfd = dup(0);
	int				fds[2];
	char			*line;
	int				error;

	if (pipe(fds))
		return (1);
	signal(SIGINT, heredoc_handler);
	error = 0;
	while (!error)
	{
		line = readline("> ");
		error = heredoc_parse_line(fds[1], line, eof);
		free(line);
	}
	close(fds[1]);
	*target_fd = fds[0];
	fds[0] = g_lastsignal;
	update_status_signal();
	signal(SIGINT, prompt_handler);
	dup2(stdinfd, 0);
	close(stdinfd);
	return (fds[0] != 0);
}

static int	heredoc_parse_line(const int fd, char *input, const char *const eof)
{
	char	*line;

	if (!input || g_lastsignal)
	{
		if (!g_lastsignal)
			print_error(NULL, NULL, "warning: heredoc delimited by eof");
		return (1);
	}
	line = NULL;
	expand_str(&line, &input);
	if (!ft_strcmp(line, eof))
	{
		free(line);
		return (1);
	}
	ft_putendl_fd(line, fd);
	free(line);
	return (0);
}
