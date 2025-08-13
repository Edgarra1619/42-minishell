#ifndef FD_H
# define FD_H

#include <minishell/types.h>

int	redirect_fd(t_redir *redir);
int	close_fd(int *fd);

#endif
