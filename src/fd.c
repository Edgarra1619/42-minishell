#include <minishell/types.h>
#include <minishell/path.h>

#include <fcntl.h>

int	close_fd(int *fd);

int	redirect_fd(t_redir *const redir)
{
	const static mode_t	open_mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;

	if (redir->target_fd < 0)
	{
		if (!(redir->open_flags & O_WRONLY)
			&& validate_file_path(redir->target_path))
			return (1);
		redir->target_fd = open(
				redir->target_path, redir->open_flags, open_mode);
		if (redir->target_fd == -1)
			return (1);
	}
	if (dup2(redir->target_fd, redir->source_fd) == -1)
		return (1);
	close_fd(&redir->target_fd);
	return (0);
}

int	close_fd(int *const fd)
{
	int	ret;

	if (*fd < 0)
		return (0);
	ret = close(*fd);
	if (!ret)
		*fd = -1;
	return (ret);
}
