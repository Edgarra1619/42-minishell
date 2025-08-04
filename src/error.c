#include <libft.h>

#include <string.h>
#include <errno.h>
#include <unistd.h>

static void	buffer_error(const char *str);

int	print_error(const char *const command, const char *const path,
	const char *const var, const char *const error)
{
	buffer_error("minishell: ");
	if (command)
	{
		buffer_error(command);
		buffer_error(": ");
	}
	if (path)
	{
		buffer_error(path);
		buffer_error(": ");
	}
	if (var)
	{
		buffer_error("'");
		buffer_error(var);
		buffer_error("': ");
	}
	if (error)
		buffer_error(error);
	else
		buffer_error(strerror(errno));
	buffer_error("\n");
	buffer_error(NULL);
	return (1);
}

//flushes on NULL
static void	buffer_error(const char *str)
{
	static char	buffer[1024];

	if (!str)
	{
		write(2, buffer, ft_strlen(buffer));
		buffer[0] = 0;
	}
	else
		ft_strlcat(buffer, str, 1024);
}
