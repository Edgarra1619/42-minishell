#include <minishell/minishell.h>
#include <minishell/env.h>
#include <minishell/error.h>
#include <libft.h>

static int	validate_var(const char *const var);
static int	is_valid_key(const char *var);

int	export(char **argv)
{
	int	ret;

	if (!argv[1])
		return (0);
	ret = 0;
	while (*++argv)
	{
		if (validate_var(*argv))
		{
			ret = 1;
			continue ;
		}
		if (!ft_strchr(*argv, '='))
			continue ;
		set_var(*argv);
	}
	return (ret);
}

static int	validate_var(const char *const var)
{
	int	*varc;

	get_env(&varc, NULL, NULL);
	if (*varc >= ENV_MAX)
		return (print_var_error("export", var, "too many variables"));
	if (ft_strlen(var) >= VAR_MAX)
		return (print_var_error("export", var, "variable too long"));
	if (!is_valid_key(var))
		return (print_var_error("export", var, "not a valid identifier"));
	return (0);
}

static int	is_valid_key(const char *var)
{
	if (!*var || *var == '=' || ft_isdigit(*var))
		return (0);
	while (*var && *var != '=')
	{
		if (!ft_isalnum(*var) && *var != '_')
			return (0);
		var++;
	}
	return (1);
}
