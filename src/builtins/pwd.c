#include <libft.h>

#include <unistd.h>
#include <limits.h>
#include <stdbool.h>

int	pwd_builtin(const bool print_output)
{
	char	buffer[PATH_MAX];

	if (getcwd(buffer, PATH_MAX))
	{
		if (print_output)
			ft_putendl_fd(buffer, 1);
		return (0);
	}
	return (1);
}
