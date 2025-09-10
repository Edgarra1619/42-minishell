#include <minishell/env.h>
#include <libft.h>

int	export_builtin(char **argv, const bool print_output)
{
	int		ret;
	char	**envp;

	if (!argv[1] || !ft_strcmp(argv[1], "-p"))
	{
		if (!print_output)
			return (0);
		get_env(NULL, NULL, &envp, NULL);
		while (*envp)
		{
			ft_putstr_fd("export ", 1);
			ft_putendl_fd(*envp++, 1);
		}
		return (0);
	}
	ret = 0;
	while (*++argv)
		ret |= set_var(*argv, print_output);
	return (ret);
}
