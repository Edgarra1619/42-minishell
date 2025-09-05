#include <minishell/env.h>
#include <libft.h>

int	export_builtin(char **argv, const bool print_output)
{
	int	ret;

	if (!argv[1])
		return (0);
	ret = 0;
	while (*++argv)
		ret |= set_var(*argv, print_output);
	return (ret);
}
