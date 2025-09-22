#include <minishell/exit.h>
#include <minishell/tokenizer.h>

#include <libft.h>
#include <stdbool.h>

int	parse_quotes(char **arg, char **str, bool dquote)
{
	char *const	end = ft_strchr(*str, '\'' - 5 * dquote);

	*end = 0;
	if (!dquote)
	{
		ft_strappend(arg, *str);
		*end = '\'';
		*str = end + 1;
		return (!*arg);
	}
	expand_str(arg, str);
	if (!ft_strappend(arg, *str))
		clear_exit(1);
	*end = '"';
	*str = end + 1;
	return (!*arg);
}
