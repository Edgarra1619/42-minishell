#include <minishell/minishell.h>
#include <minishell/env.h>
#include <minishell/error.h>
#include <libft.h>

#include <stdbool.h>

static int	validate_var(const char *const var, bool print_output);
static int	is_valid_key(const char *var);

int	export(char **argv, bool print_output)
{
	int	ret;

	if (!argv[1])
		return (0);
	ret = 0;
	while (*++argv)
	{
		if (validate_var(*argv, print_output))
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

static int	validate_var(const char *const var, bool print_output)
{
	int	*varc;

	get_env(&varc, NULL, NULL, NULL);
	if (*varc >= ENV_MAX)
	{
		if (print_output)
			return (print_var_error(var, "too many variables"));
		return (1);
	}
	if (ft_strlen(var) >= VAR_MAX)
	{
		if (print_output)
			return (print_var_error(var, "variable too long"));
		return (1);
	}
	if (!is_valid_key(var))
	{
		if (print_output)
			return (print_var_error(var, "not a valid identifier"));
		return (1);
	}
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
