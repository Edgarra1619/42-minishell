#include <minishell.h>
#include <libft.h>
#include <limits.h>
#include <sys/stat.h>
#include <errno.h>

int	validate_file_path(const char *const path);
static int	find_cmd_path(const char *const cmd, char *const buffer);

int	resolve_cmd_path(const char *const cmd, char *const buffer)
{
	if (ft_strchr(cmd, '/'))
	{
		ft_strlcpy(buffer, cmd, PATH_MAX);
		return (validate_file_path(buffer));
	}
	return (find_cmd_path(cmd, buffer));
}

int	validate_file_path(const char *const path)
{
	struct stat	file_info;

	if (stat(path, &file_info))
		return (1);
	else if (S_ISDIR(file_info.st_mode))
	{
		errno = EISDIR;
		return (1);
	}
	return (0);
}

static int	find_cmd_path(const char *const cmd, char *const buffer)
{
	const char	*path_var = get_var("PATH");
	int			path_len;

	while (path_var && *path_var)
	{
		path_len = ft_strlen_delim(path_var, ':');
		ft_strlcpy(buffer, path_var, ft_min(path_len + 1, PATH_MAX));
		ft_strlcat(buffer, "/", PATH_MAX);
		ft_strlcat(buffer, cmd, PATH_MAX);
		if (!validate_file_path(buffer))
			return (0);
		path_var += path_len + 1;
	}
	return (1);
}
