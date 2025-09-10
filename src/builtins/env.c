#include <minishell/env.h>
#include <libft.h>

int	env_builtin(void)
{
	char	**envp;

	get_env(NULL, NULL, &envp, NULL);
	while (*envp)
	{
		if (ft_strchr(*envp, '='))
			ft_putendl_fd(*envp, 1);
		envp++;
	}
	return (0);
}
