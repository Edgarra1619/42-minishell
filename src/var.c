#include <minishell/minishell.h>
#include <minishell/env.h>
#include <minishell/error.h>
#include <libft.h>

#include <stdbool.h>
#include <limits.h>
#include <unistd.h>

static int	is_valid_key(const char *var);

void	update_pwd(const bool print_output)
{
	char *const	pwd = get_var("PWD");
	char		buffer[VAR_MAX];
	char		cwd[PATH_MAX];

	if (pwd)
	{
		ft_strlcpy(buffer, "OLDPWD=", VAR_MAX);
			ft_strlcat(buffer, pwd, VAR_MAX);
		set_var(buffer, print_output);
	}
	ft_strlcpy(buffer, "PWD=", VAR_MAX);
	if (getcwd(cwd, PATH_MAX))
		ft_strlcat(buffer, cwd, VAR_MAX);
	set_var(buffer, print_output);
}

void	update_shlvl(int add, const bool print_output)
{
	char *const shlvl = get_var("SHLVL");

	if (!shlvl)
	{
		set_var("SHLVL=1", print_output);
		return ;
	}
	ft_itoa_cpy(shlvl, ft_max(ft_atoi(shlvl) + add, 0));
}

int	validate_var(const char *const var, const bool print_output)
{
	int	*varc;

	get_env(&varc, NULL, NULL, NULL);
	if (!get_var(var) && *varc >= ENV_MAX)
	{
		if (print_output)
			print_var_error(var, "too many variables");
		return (1);
	}
	if (ft_strlen(var) >= VAR_MAX)
	{
		if (print_output)
			print_var_error(var, "variable too long");
		return (1);
	}
	if (!is_valid_key(var))
	{
		if (print_output)
			print_var_error(var, "not a valid identifier");
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
