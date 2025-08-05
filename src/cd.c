#include <minishell/minishell.h>
#include <minishell/env.h>
#include <minishell/error.h>
#include <libft.h>

#include <unistd.h>
#include <limits.h>

static int	resolve_path(const char **const path, int *const print);
static void	update_pwd(void);

int	cd(int argc, char **argv)
{
	const char	*path = argv[1];
	int			print;

	if (argc > 2)
		return (print_error("cd", NULL, "too many arguments"));
	if (resolve_path(&path, &print))
		return (1);
	if (!*path)
		return (0);
	if (chdir(path))
		return (print_error("cd", path, NULL));
	if (print)
		ft_putendl_fd(path, 1);
	update_pwd();
	return (0);
}

static int	resolve_path(const char **const path, int *const print)
{
	*print = 0;
	if (!*path)
	{
		*path = get_var("HOME");
		if (!*path)
			return (print_error("cd", NULL, "HOME not set"));
	}
	else if (!ft_strcmp(*path, "-"))
	{
		*path = get_var("OLDPWD");
		if (!*path)
			return (print_error("cd", NULL, "OLDPWD not set"));
		*print = 1;
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
