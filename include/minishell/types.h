/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-albu <vde-albu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:53:59 by vde-albu          #+#    #+#             */
/*   Updated: 2025/09/23 14:54:08 by vde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include <minishell/minishell.h>

# include <limits.h>
# include <fcntl.h>

typedef enum e_open_flags
{
	OPEN_READ = O_RDONLY,
	OPEN_WRITE = O_WRONLY | O_CREAT | O_TRUNC,
	OPEN_RDWR = O_RDWR | O_CREAT,
	OPEN_APPEND = O_WRONLY | O_CREAT | O_APPEND,
	OPEN_HEREDOC
}	t_open_flags;

typedef struct s_redir
{
	int				source_fd;
	int				target_fd;
	char			**target_path;
	t_open_flags	open_flags;
}	t_redir;

typedef struct s_cmd
{
	char	*cmd;
	char	path[PATH_MAX];
	char	**argv;
	int		num_redirs;
	t_redir	pipes[2];
	t_redir	redirs[REDIR_MAX];
	pid_t	pid;
}	t_cmd;

typedef struct s_pipeline
{
	char	*prompt;
	int		num_cmds;
	t_cmd	*cmds;
}	t_pipeline;

#endif
