#include <minishell/types.h>
#include <minishell/path.h>
#include <minishell/error.h>
#include <minishell/exit.h>
#include <libft.h>

#include <readline/readline.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>

void	redirect_fd(t_redir *const redir)
{
	const static mode_t	open_mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;

	if (redir->target_path)
	{
		if (!(redir->open_flags & O_WRONLY)
			&& validate_file_path(redir->target_path))
			clear_exit(print_error(NULL, redir->target_path, NULL));
		redir->target_fd
			= open(redir->target_path, redir->open_flags, open_mode);
		if (redir->target_fd == -1)
			clear_exit(print_error(NULL, redir->target_path, NULL));
	}
	if (dup2(redir->target_fd, redir->source_fd) == -1)
		error_exit(1);
	close(redir->target_fd);
}

int	open_heredoc(int *const target_fd, const char *const eof)
{
	int		fds[2];
	char	*line;

	if (pipe(fds))
		return (1);
	line = NULL;
	while (1)
	{
		line = readline("> ");
		if (!line)
		{
			print_error(NULL, NULL, "warning: heredoc delimited by eof");
			break ;
		}
		if (!ft_strcmp(line, eof))
		{
			free(line);
			break ;
		}
		ft_putendl_fd(line, fds[1]);
		free(line);
	}
	close(fds[1]);
	*target_fd = fds[0];
	return (0);
}

int	close_fd(int *const fd)
{
	if (*fd < 0)
		return (0);
	if (close(*fd))
		return (1);
	*fd = -1;
	return (0);
}

void	close_unused_fds(const t_cmd *const cmd)
{
	bool	fds[FD_MAX];
	int		i;

	ft_bzero(fds, sizeof(bool) * FD_MAX);
	fds[0] = true;
	fds[1] = true;
	fds[2] = true;
	if (cmd)
	{
		i = -1;
		while (++i < cmd->num_redirs)
			fds[cmd->redirs[i].source_fd] = true;
	}
	i = -1;
	while (++i < FD_MAX)
	{
		if (!fds[i])
			close(i);
	}
}
