#ifndef MINISHELL_H
# define MINISHELL_H

# define VAR_MAX 5120
# define ENV_MAX 1024

int		echo(char **argv);
int		pwd(void);
int		env(void);
int		export(char **argv);
void	get_env(int **varc, char **vars, char ***envp);
char	*get_var(const char *var);
int		set_var(const char *var);
int		print_error(const char *command, const char *path, const char *var,
			const char *error);

#endif
