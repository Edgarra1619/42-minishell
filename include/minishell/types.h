#include <sys/types.h>
#include <unistd.h>

typedef struct s_redir
{
	int		fd;
	int		target_fd;
	char	*target_path;
	int		flags;
	mode_t	mode;
}	t_redir;

typedef struct s_cmd
{
	char	**args;
	t_redir	*redirs;
	pid_t	pid;
	int		status;
}	t_cmd;
