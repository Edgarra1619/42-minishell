#include <minishell/env.h>
#include <libft.h>

int	unset_builtin(char **argv)
{
	while (*++argv)
		remove_var(*argv);
	return (0);
}
