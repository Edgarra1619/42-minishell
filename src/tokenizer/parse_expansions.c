#include <minishell/env.h>
#include <minishell/exit.h>
#include <minishell/tokenizer.h>

#include <libft.h>

#include <stdlib.h>

static int	expand_qm(int *argc, char ***arg, char **str, const bool inquotes)
{
	char	*temp;

	get_env(NULL, NULL, NULL, &temp);
	temp = ft_itoa((unsigned int) *temp);
	if (!temp)
		clear_exit (1);
	ft_strappend(*arg + *argc * !inquotes, temp);
	free(temp);
	(*str)++;
	if (!*(*arg + *argc * !inquotes))
		clear_exit (1);
	return (0);
}

static void	expand_var(char **value, int *argc, char ***arg)
{
	char	*next;

	next = ft_strchr(*value, ' ');
	while (next)
	{
		if (append_args(*arg + *argc, *value, next))
			clear_exit (1);
		parse_whtspc(argc, arg, &*value);
		*value = next + 1;
		next = ft_strchr(*value, ' ');
	}
	if (!ft_strappend(*arg + *argc, *value))
		clear_exit (1);
}

//TODO make it so expansion to empty string puts an empty string
int	parse_expans(int *argc, char ***arg, char **str, bool inquotes)
{
	int		fake_argc;
	char	*value;

	fake_argc = 0;
	if (!argc)
		argc = &fake_argc;
	if (**str == '?')
		return (expand_qm(argc, arg, str, inquotes));
	if (!(**str == '_' || ft_isalpha(**str)))
	{
		if(!ft_strappend(*arg + *argc * !inquotes, "$"))
			clear_exit(1);
		else
			return (0);
	}
	value = get_var(*str);
	while (**str == '_' || ft_isalnum(**str))
		(*str)++;
	if (!value)
		return (0);
	if (inquotes)
		return (!ft_strappend(*arg + *argc, value));
	expand_var(&value, argc, arg);
	return (0);
}
