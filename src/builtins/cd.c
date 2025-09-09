#include <minishell/env.h>
#include <minishell/error.h>
#include <libft.h>

#include <unistd.h>

static int	resolve_path(const char **path, bool *print_cwd,
				bool print_output);

int	cd_builtin(char **argv, const bool print_output)
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
	update_pwd(print_output);
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
