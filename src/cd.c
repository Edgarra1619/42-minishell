#include <minishell/minishell.h>
#include <minishell/env.h>
#include <minishell/error.h>
#include <libft.h>

#include <unistd.h>
#include <limits.h>
#include <stdbool.h>

static int	resolve_path(const char **const path, bool *const print_cwd,
				const bool print_output);
static void	update_pwd(void);

int	cd(char **argv, bool print_output)
{
	const char	*path = argv[1];
	bool		print_cwd;

	if (argv[1] && argv[2])
	{
		if (print_output)
			return (print_error("cd", NULL, "too many arguments"));
		return (1);
	}
	if (resolve_path(&path, &print_cwd, print_output))
		return (1);
	if (!*path)
		return (0);
	if (chdir(path))
	{
		if (print_output)
			return (print_error("cd", path, NULL));
		return (1);
	}
	if (print_output && print_cwd)
		ft_putendl_fd(path, 1);
	update_pwd();
	return (0);
}

static int	resolve_path(const char **const path, bool *const print_cwd,
	const bool print_output)
{
	*print_cwd = false;
	if (!*path)
	{
		*path = get_var("HOME");
		if (!*path)
		{
			if (print_output)
				return (print_error("cd", NULL, "HOME not set"));
			return (1);
		}
	}
	else if (!ft_strcmp(*path, "-"))
	{
		*path = get_var("OLDPWD");
		if (!*path)
		{
			if (print_output)
				return (print_error("cd", NULL, "OLDPWD not set"));
			return (1);
		}
		*print_cwd = true;
	}
	return (0);
}

static void	update_pwd(void)
{
	const char	*pwd = get_var("PWD");
	char		buffer[VAR_MAX];
	char		cwd[PATH_MAX];

	ft_strlcpy(buffer, "OLDPWD=", VAR_MAX);
	if (pwd)
		ft_strlcat(buffer, pwd, VAR_MAX);
	set_var(buffer);
	ft_strlcpy(buffer, "PWD=", VAR_MAX);
	if (getcwd(cwd, PATH_MAX))
		ft_strlcat(buffer, cwd, VAR_MAX);
	set_var(buffer);
}
