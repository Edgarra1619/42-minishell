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
	char	path[PATH_MAX];
	char	**argv;
	int		pipe[2];
	t_redir	redirs[REDIR_MAX];
	pid_t	pid;
	int		status;
}	t_cmd;
