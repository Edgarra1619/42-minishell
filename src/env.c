#include <minishell.h>
#include <libft.h>

void		get_env(int **varc, char **vars, char ***envp);
static int	get_key_len(const char *const var);

int	env(void)
{
	char	**envp;

	get_env(NULL, NULL, &envp);
	while (*envp)
		ft_putendl_fd(*envp++, 1);
	return (0);
}

void	get_env(int **varc, char **vars, char ***envp)
{
	static int	s_varc;
	static char	s_vars[ENV_MAX][VAR_MAX];
	static char	*s_envp[ENV_MAX + 1];

	if (varc)
		*varc = &s_varc;
	if (vars)
		*vars = (char *)s_vars;
	if (envp)
		*envp = s_envp;
}

char	*get_var(const char *const key)
{
	char		**envp;
	const int	key_len = ft_strlen(key);

	get_env(NULL, NULL, &envp);
	while (*envp)
	{
		if (key_len == get_key_len(*envp) && !ft_strncmp(key, *envp, key_len))
			return (*envp + key_len + 1);
		++envp;
	}
	return (NULL);
}

int	set_var(const char *const var)
{
	int			*varc;
	char		*vars;
	char		**envp;
	const int	key_len = get_key_len(var);

	get_env(&varc, &vars, &envp);
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
	int			*varc;
	char		*vars;
	char		**envp;
	const int	key_len = ft_strlen(key);

	get_env(&varc, &vars, &envp);
	while (*envp)
	{
		if (key_len == get_key_len(*envp) && !ft_strncmp(key, *envp, key_len))
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

static int	get_key_len(const char *const var)
{
	int	i;

	i = 0;
	while (var[i] && var[i] != '=')
		i++;
	return (i);
}
