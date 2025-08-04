#ifndef MINISHELL_H
# define MINISHELL_H
# include <unistd.h>
# include <sys/types.h>

# define VAR_MAX 5120
# define ENV_MAX 1024

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

int		echo(char **argv);
int		pwd(void);
int		cd(int argc, char **argv);
int		export(char **argv);
int		unset(char **argv);
int		env(void);
void	init_env(const char **envp);
void	get_env(int **varc, char **vars, char ***envp);
char	*get_var(const char *key);
int		set_var(const char *var);
int		remove_var(const char *key);
int		resolve_cmd_path(const char *cmd, char *buffer);
int		validate_file_path(const char *path);
int		print_error(const char *command, const char *path, const char *var,
			const char *error);

#endif
