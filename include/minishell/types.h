#ifndef TYPES_H
# define TYPES_H

# include <minishell/minishell.h>

# include <limits.h>
# include <fcntl.h>

typedef enum e_open_flags
{
	OPEN_READ = O_RDONLY,
	OPEN_WRITE = O_WRONLY | O_CREAT | O_TRUNC,
	OPEN_APPEND = O_WRONLY | O_CREAT | O_APPEND
}	t_open_flags;

typedef struct s_redir
{
	int				source_fd;
	int				target_fd;
	char			*target_path;
	char			*heredoc_eof;
	t_open_flags	open_flags;
}	t_redir;

typedef struct s_cmd
{
	char	*cmd;
	char	path[PATH_MAX];
	char	**argv;
	int		num_redirs;
	t_redir	redirs[REDIR_MAX];
	pid_t	pid;
	int		status;
}	t_cmd;

typedef struct s_pipeline
{
	char	*prompt;
	int		num_cmds;
	t_cmd	*cmds;
}	t_pipeline;

#endif
