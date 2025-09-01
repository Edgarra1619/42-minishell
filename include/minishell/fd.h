#ifndef FD_H
# define FD_H

# include <minishell/types.h>

int		redirect_fd(t_redir *redir);
int		open_heredoc(int *target_fd, const char *eof);
int		close_fd(int *fd);
void	close_unused_fds(const t_cmd *cmd);

#endif
