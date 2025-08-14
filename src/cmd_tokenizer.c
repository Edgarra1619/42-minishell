#include <minishell/types.h>
#include <minishell/env.h>
#include <libft.h>

#include <stdlib.h>
#include <stdbool.h>

static int	append_args(char **arg, char *str, char *end);
static char	*find_next_special(char *str);
static int	parse_whtspc(int *argc, char ***arg, char **str);
static int	parse_quotes(char **arg, char **str, bool dquote);
static int	parse_extens(int *argc, char ***arg, char **str, bool inquotes);

int	tokenize_cmd(t_cmd *cmd)
{
	int		argc;
	char	*tmp;

	argc = 0;
	if (!cmd->cmd)
		return (0);
	cmd->argv = ft_calloc(sizeof(char *), argc + 2);
	while (*(cmd->cmd))
	{
		tmp = find_next_special(cmd->cmd);
		if (*tmp == '<' || *tmp == '>')
		{
			cmd->cmd = tmp + 1;
			continue;
		}
		if (append_args(cmd->argv + argc, cmd->cmd, tmp))
			return (1);
		cmd->cmd = tmp + !!*tmp;
		if (ft_isspace(*tmp))
			parse_whtspc(&argc, &(cmd->argv), &(cmd->cmd));
		if (*tmp == '\'' || *tmp == '"')
			parse_quotes(cmd->argv + argc, &cmd->cmd, *tmp == '"');
		if (*tmp == '$')
			parse_extens(&argc, &(cmd->argv), &(cmd->cmd), false);
	}
	return (0);
}

static int	parse_extens(int *argc, char ***arg, char **str, bool inquotes)
{
	char	*temp;
	char	*next;

	get_env(NULL, NULL, NULL, &temp);
	if (**str == '?')
	{
		temp = ft_itoa(*temp);
		if (!temp)
			return (1);
		ft_strappend(*arg + *argc * !inquotes, temp);
		free(temp);
		return (!!*(*arg + *argc * !inquotes));
	}
	if (!(**str == '_' || ft_isalpha(**str)))
		ft_strappend(*arg + *argc * !inquotes, "$");
	temp = get_var_safe(*str);
	if (inquotes || !temp)
		return (!ft_strappend(*arg, temp));
	next = ft_strchr(temp, ' ');
	while (*next)
	{
		if (!append_args(*arg + *argc, temp, next))
			return (1);
		parse_whtspc(argc, arg, &temp);
		temp = next + 1;
		next = ft_strchr(temp, ' ');
	}
	return (!ft_strappend(*arg + *argc, temp));
}

static int	append_args(char **arg, char *str, char *end)
{
	const char	tmp = *end;

	*end = 0;
	ft_strappend(arg, str);
	*end = tmp;
	return (!*arg);
}

static int	parse_redirs(t_cmd *cmd, char *str)
{
	(void) cmd;
	(void) str;
	return (0);
}

static int	parse_quotes(char **arg, char **str, bool dquote)
{
	char *const	end = ft_strchr(*str, '\'' - 5 * dquote);
	char		*tmp;

	*end = 0;
	if (!dquote)
	{
		ft_strappend(arg, *str);
		*end = '\'';
		*str = end + 1;
		return (!*arg);
	}
	tmp = ft_strchr(*str, '$');
	while (tmp)
	{
		*tmp = 0;
		if (!ft_strappend(arg, *str))
			return (1);
		*tmp = '$';
		*str = tmp + 1;
		if (!parse_extens(NULL, &arg, str, true))
			return (1);
		tmp = ft_strchr(*str, '$');
	}
	ft_strappend(arg, *str);
	*end = '"';
	*str = end + 1;
	return (!*arg);
}

static int	parse_whtspc(int *argc, char ***arg, char **str)
{
	char	**new;

	while (ft_isspace(**str))
		(*str)++;
	if (!((*arg)[*argc]))
		return (0);
	(*argc)++;
	new = ft_realloc(*arg, sizeof(char*) * (*argc + 1), sizeof(char*) * (*argc + 2));
	if (!new)
	{
		new = *arg;
		while (*new)
			free((*new)++);
		free(*arg);
		return (1);
	}
	*arg = new;
	(*arg)[*argc + 1] = NULL;
	return (0);
}

static char	*find_next_special(char *str)
{
	while (*str)
	{
		if (*str == '$' || ft_isspace(*str) || *str == '\'' || *str == '"')
			return (str);
		str++;
	}
	return (str);
}
