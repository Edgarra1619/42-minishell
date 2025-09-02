#include <minishell/env.h>

int	unset_builtin(char **argv)
{
	while (*++argv)
		remove_var(*argv);
	return (0);
}
