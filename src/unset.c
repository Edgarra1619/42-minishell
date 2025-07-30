#include <minishell.h>

int	unset(char **argv)
{
	while (*++argv)
		remove_var(*argv);
	return (0);
}
