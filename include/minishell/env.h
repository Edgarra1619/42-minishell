#ifndef ENV_H
# define ENV_H

# include <stdbool.h>

void	init_env(char **envp);
void	get_env(int **varc, char **vars, char ***envp, char **status);
char	*get_var(const char *key);
char	*get_var_safe(const char *key);
int		set_var(const char *var, bool print_output);
int		validate_var(const char *var, bool print_output);
int		remove_var(const char *key);
void	update_pwd(bool print_output);
void	update_shlvl(int add, bool print_output);

#endif
