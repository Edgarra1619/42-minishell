/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-albu <vde-albu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:55:13 by vde-albu          #+#    #+#             */
/*   Updated: 2025/09/23 14:55:13 by vde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FD_H
# define FD_H

# include <minishell/types.h>

void	redirect_fd(t_redir *redir);
int		open_heredoc(int *target_fd, const char *eof);
int		close_fd(int *fd);
void	close_unused_fds(const t_cmd *cmd);

#endif
