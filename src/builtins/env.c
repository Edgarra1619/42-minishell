#include <minishell/env.h>
#include <libft.h>

int	env_builtin(void)
{
	char	**envp;

	get_env(NULL, NULL, &envp, NULL);
	while (*envp)
		ft_putendl_fd(*envp++, 1);
	return (0);
}
