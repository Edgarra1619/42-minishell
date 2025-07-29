#include <minishell.h>
#include <libft.h>

void	get_env(int **varc, char **vars, char ***envp);

int	env(void)
{
	char	**envp;

	get_env(NULL, NULL, &envp);
	while (*envp)
		ft_putendl_fd(*envp++, 1);
	return (0);
}

void	get_env(int **varc, char **vars, char ***envp)
{
	static int	s_varc;
	static char	s_vars[ENV_MAX][VAR_MAX];
	static char	*s_envp[ENV_MAX + 1];

	if (varc)
		*varc = &s_varc;
	if (vars)
		*vars = (char *)s_vars;
	if (envp)
		*envp = s_envp;
}
