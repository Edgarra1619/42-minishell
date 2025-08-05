#include <minishell/minishell.h>
#include <libft.h>

#include <string.h>
#include <errno.h>
#include <unistd.h>

void	buffer_error(const char *str);

int	print_error(const char *const command, const char *const path,
	const char *const error)
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
	if (error)
		buffer_error(error);
	else
		buffer_error(strerror(errno));
	buffer_error("\n");
	buffer_error(NULL);
	return (1);
}

int	print_var_error(const char *const command, const char *const var,
	const char *const error)
{
	char	buffer[VAR_MAX + 2];

	buffer[0] = '`';
	ft_strlcpy(buffer + 1, var, VAR_MAX);
	ft_strlcat(buffer, "'", VAR_MAX + 2);
	return (print_error(command, buffer, error));
}

//flushes on NULL
void	buffer_error(const char *str)
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
