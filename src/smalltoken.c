#include <minishell/types.h>
#include <minishell/env.h>
#include <libft.h>

#include <stdbool.h>

t_cmd	parse_cmd(char *str)
{
	t_cmd	cmd;
	int		i;
	int		argc;

	i = 0;
	argc = 0;
//	cmd.args = ft_calloc(sizeof(char *), argc + 2);
	while (str)
	{


	}
	

}

static int	parse_quotes(char **arg, char *str, bool dquote)
{
	char *const	end = ft_strchr(str, '\'' - 5 * dquote);
	char		*tmp;

	*end = 0;
	if (!dquote)
	{
		ft_strappend(arg, str);
		*end = '\'';
		return (!*arg);
	}
	tmp = ft_strchr(str, '$');
	while (tmp)
	{
		*tmp = 0;
		if (!ft_strappend(arg, str))
			return (1);
		*tmp = '$';
		str = tmp + 1;
		if (!ft_strappend(arg, get_var_safe(str)))
			return (1);
		tmp = ft_strchr(str, '$');
	}
	ft_strappend(arg, str);
	*end = '"';
	return (0);
}
