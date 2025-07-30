#ifndef MINISHELL_H
# define MINISHELL_H

# define VAR_MAX 5120
# define ENV_MAX 1024

int		echo(char **argv);
int		pwd(void);
int		cd(int argc, char **argv);
int		export(char **argv);
int		unset(char **argv);
int		env(void);
void	get_env(int **varc, char **vars, char ***envp);
char	*get_var(const char *key);
int		set_var(const char *var);
int		remove_var(const char *key);
int		resolve_cmd_path(const char *cmd, char *buffer);
int		print_error(const char *command, const char *path, const char *var,
			const char *error);

#endif
