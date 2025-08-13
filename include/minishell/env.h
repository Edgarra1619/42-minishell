void	init_env(char **envp);
void	get_env(int **varc, char **vars, char ***envp, char **status);
char	*get_var(const char *key);
char	*get_var_safe(const char *key);
int		set_var(const char *var);
int		remove_var(const char *key);
