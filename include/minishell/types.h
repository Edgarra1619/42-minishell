#ifndef TYPES_H
# define TYPES_H

#include <minishell/minishell.h>

#include <sys/types.h>
#include <limits.h>
#include <unistd.h>

typedef struct s_redir
{
	int		source_fd;
	int		target_fd;
	char	*target_path;
	int		open_flags;
}	t_redir;

typedef struct s_cmd
{
	char	*cmd;
	char	path[PATH_MAX];
	char	**argv;
	int		pipe[2];
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
