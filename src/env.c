#include <minishell/minishell.h>
#include <libft.h>

void	get_env(int **varc, char **vars, char ***envp, char **status);

int	env(void)
{
	char	**envp;

	get_env(NULL, NULL, &envp, NULL);
	while (*envp)
		ft_putendl_fd(*envp++, 1);
	return (0);
}

void	get_env(int **varc, char **vars, char ***envp, char **status)
{
	static int	s_varc;
	static char	s_vars[ENV_MAX][VAR_MAX];
	static char	*s_envp[ENV_MAX + 1];
	static char	s_status;

	if (varc)
		*varc = &s_varc;
	if (vars)
		*vars = (char *)s_vars;
	if (envp)
		*envp = s_envp;
	if (status)
		*status = &s_status;
}

char	*get_var(const char *const key)
{
	const size_t	key_len = ft_strlen(key);
	char			**envp;

	get_env(NULL, NULL, &envp, NULL);
	while (*envp)
	{
		if (key_len == ft_strlen_delim(*envp, '=')
			&& !ft_strncmp(key, *envp, key_len))
			return (*envp + key_len + 1);
		++envp;
	}
	return (NULL);
}

char	*get_var_safe(const char *const key)
{
	size_t	key_len;
	char	**envp;

	if (!(key[0] == '_' || ft_isalpha(key[0])))
		return (NULL);
	key_len = 0;
	while (ft_isalnum(key[key_len]) || key[key_len] == '_')
		key_len++;
	get_env(NULL, NULL, &envp, NULL);
	while (*envp)
	{
		if (key_len == ft_strlen_delim(*envp, '=')
			&& !ft_strncmp(key, *envp, key_len))
			return (*envp + key_len + 1);
		++envp;
	}
	return (NULL);
}

int	set_var(const char *const var)
{
	const int	key_len = ft_strlen_delim(var, '=');
	int			*varc;
	char		*vars;
	char		**envp;

	get_env(&varc, &vars, &envp, NULL);
	if (*varc >= ENV_MAX || !ft_strchr(var, '='))
		return (1);
	while (*envp && ft_strncmp(*envp, var, key_len + 1))
		++envp;
	if (!*envp)
	{
		while (*vars)
			vars += VAR_MAX;
		*envp = vars;
		++*varc;
	}
	ft_strlcpy(*envp, var, VAR_MAX);
	return (0);
}

int	remove_var(const char *const key)
{
	int				*varc;
	char			*vars;
	char			**envp;
	const size_t	key_len = ft_strlen(key);

	get_env(&varc, &vars, &envp, NULL);
	while (*envp)
	{
		if (key_len == ft_strlen_delim(*envp, '=')
			&& !ft_strncmp(key, *envp, key_len))
			break ;
		++envp;
	}
	if (!*envp)
		return (1);
	**envp = '\0';
	*envp = NULL;
	--*varc;
	while (envp[1])
	{
		*envp = envp[1];
		envp[1] = NULL;
		++envp;
	}
	return (0);
}
