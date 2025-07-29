#include <libft.h>
#include <string.h>
#include <errno.h>

int	print_error(const char *const command, const char *const path,
	const char *const var, const char *const error)
{
	ft_putstr_fd("minishell: ", 2);
	if (command)
	{
		ft_putstr_fd(command, 2);
		ft_putstr_fd(": ", 2);
	}
	if (path)
	{
		ft_putstr_fd(path, 2);
		ft_putstr_fd(": ", 2);
	}
	if (var)
	{
		ft_putstr_fd("`", 2);
		ft_putstr_fd(var, 2);
		ft_putstr_fd("': ", 2);
	}
	if (error)
		ft_putendl_fd(error, 2);
	else
		ft_putendl_fd(strerror(errno), 2);
	return (1);
}
