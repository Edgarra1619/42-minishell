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

char	*get_var(const char *const var)
{
	char		**envp;
	const int	key_len = get_key_len(var);

	get_env(NULL, NULL, &envp);
	while (*envp)
	{
		if (!ft_strncmp(*envp, var, key_len) && (*envp)[key_len] == '=')
			return (*envp + key_len + 1);
		envp++;
	}
	return (NULL);
}

int	set_var(const char *const var)
{
	int			*varc;
	char		*varv;
	char		**envp;
	const int	key_len = get_key_len(var);

	get_env(&varc, &varv, &envp);
	if (*varc >= ENV_MAX || !ft_strchr(var, '='))
		return (1);
	while (*envp && ft_strncmp(*envp, var, key_len + 1))
		++envp;
	if (!*envp)
	{
		while (*varv)
			varv += VAR_MAX;
		*envp = varv;
		++*varc;
	}
	ft_strlcpy(*envp, var, VAR_MAX);
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
