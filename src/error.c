#include <minishell/minishell.h>
#include <minishell/pipeline.h>
#include <libft.h>

#include <errno.h>
#include <unistd.h>
#include <string.h>

static void	buffer_error(const char *str);

int	get_error_status(void)
{
	if (errno == 2)
		return (127);
	if (errno == 13 || errno == 21)
		return (126);
	return (1);
}

int	print_error(const char *const cmd, const char *const path,
	const char *const error)
{
	if (cmd)
	{
		buffer_error(cmd);
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
	buffer_error(NULL);
	return (1);
}

int	print_var_error(const char *const cmd, const char *const var,
	const char *const error)
{
	buffer_error(cmd);
	buffer_error(": '");
	buffer_error(var);
	buffer_error("': ");
	buffer_error(error);
	buffer_error(NULL);
	return (1);
}

int	print_syntax_error(const char *const error)
{
	buffer_error("syntax error: ");
	buffer_error(error);
	buffer_error(NULL);
	return (1);
}

static void	buffer_error(const char *str)
{
	static char	buffer[ERROR_MAX];

	if (!buffer[0])
		ft_strlcat(buffer, "minishell: ", ERROR_MAX);
	if (!str)
	{
		ft_strlcat(buffer, "\n", ERROR_MAX);
		write(2, buffer, ft_strlen(buffer));
		buffer[0] = 0;
	}
	else
		ft_strlcat(buffer, str, ERROR_MAX);
}
