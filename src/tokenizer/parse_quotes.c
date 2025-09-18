#include <minishell/exit.h>
#include <minishell/tokenizer.h>

#include <libft.h>
#include <stdbool.h>

int	parse_quotes(char **arg, char **str, bool dquote)
{
	char *const	end = ft_strchr(*str, '\'' - 5 * dquote);
	char		*tmp;

	*end = 0;
	if (!dquote)
	{
		ft_strappend(arg, *str);
		*end = '\'';
		*str = end + 1;
		return (!*arg);
	}
	tmp = ft_strchr(*str, '$');
	while (tmp)
	{
		if (append_args(arg, *str, tmp))
			clear_exit(1);
		*str = tmp + 1;
		if (parse_expans(NULL, &arg, str, true))
			clear_exit(1);
		tmp = ft_strchr(*str, '$');
	}
	ft_strappend(arg, *str);
	*end = '"';
	*str = end + 1;
	return (!*arg);
}
