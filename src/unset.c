#include <minishell/env.h>

int	unset(char **argv)
{
	while (*++argv)
		remove_var(*argv);
	return (0);
}
