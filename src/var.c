#include <minishell/minishell.h>
#include <minishell/env.h>
#include <minishell/error.h>
#include <libft.h>

int	is_valid_key(const char *var);

int	validate_var(const char *const var, const bool print_output)
{
	int	*varc;

	get_env(&varc, NULL, NULL, NULL);
	if (*varc + 1 > ENV_MAX && !get_var(var))
	{
		if (print_output)
			print_var_error("export", var, "too many variables");
		return (1);
	}
	if (ft_strlen(var) >= VAR_MAX)
	{
		if (print_output)
			print_var_error("export", var, "variable too long");
		return (1);
	}
	if (!is_valid_key(var))
	{
		if (print_output)
			print_var_error("export", var, "not a valid identifier");
		return (1);
	}
	return (0);
}

int	is_valid_key(const char *var)
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
