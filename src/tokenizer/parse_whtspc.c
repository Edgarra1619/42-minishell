#include <minishell/exit.h>
#include <libft.h>

#include <stdlib.h>

int	parse_whtspc(int *argc, char ***arg, char **str)
{
	char	**new;

	while (ft_isspace(**str))
		(*str)++;
	if (!((*arg)[*argc]))
		return (0);
	(*argc)++;
	new = ft_realloc(*arg, sizeof(char *) * (*argc + 1),
			sizeof(char*) * (*argc + 2));
	if (!new)
	{
		new = *arg;
		while (*new)
			free((*new)++);
		free(*arg);
		clear_exit(1);
	}
	*arg = new;
	(*arg)[*argc + 1] = NULL;
	return (0);
}
