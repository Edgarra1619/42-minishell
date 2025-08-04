void	init_env(const char **envp);
void	get_env(int **varc, char **vars, char ***envp);
char	*get_var(const char *key);
int		set_var(const char *var);
int		remove_var(const char *key);
