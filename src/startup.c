#include <minishell/minishell.h>
#include <minishell/env.h>
#include <libft.h>

void	init_env(const char **envp)
{
	int		*varc;
	char	*vars;
	char	**n_envp;

	get_env(&varc, (char**) &vars, &n_envp);
	while (*envp)
	{
		n_envp[*varc] = vars + *varc * VAR_MAX;
		ft_strlcpy(n_envp[*varc], *envp, VAR_MAX);
		(*varc)++;
		envp++;
	}
}
