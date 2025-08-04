#include <libft.h>

#include <unistd.h>
#include <limits.h>

int	pwd(void)
{
	char	buffer[PATH_MAX];

	if (getcwd(buffer, PATH_MAX))
	{
		ft_putendl_fd(buffer, 1);
		return (0);
	}
	return (1);
}
