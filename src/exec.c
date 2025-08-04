#include <minishell.h>
#include <fcntl.h>

int	redirect_fd(t_redir *const redir)
{
	if (redir->target_fd < 0)
	{
		if (!redir->target_path)
			return (1);
		if ((redir->flags & O_WRONLY) && validate_file_path(redir->target_path))
			return (1);
		redir->target_fd = open(redir->target_path, redir->flags, redir->mode);
		if (redir->target_fd == -1)
			return (1);
	}
	if (dup2(redir->target_fd, redir->fd) == -1)
		return (1);
	if (close(redir->target_fd) == -1)
		return (1);
	redir->target_fd = -1;
	return (0);
}

