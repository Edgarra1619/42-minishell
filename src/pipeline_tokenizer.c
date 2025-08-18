#include <minishell/tokenizer.h>
#include <libft.h>

#include <stdlib.h>
#include <stdbool.h>

static bool		is_prompt_empty(const char *prompt);
static int		count_cmds(const char *prompt);
static t_cmd	*split_cmds(char *prompt, int num_cmds);

int	tokenize_pipeline(t_pipeline *const pl)
{
	pl->num_cmds = 0;
	if (is_prompt_empty(pl->prompt))
		return (0);
	if (verify_prompt_syntax(pl->prompt))
		return (1);
	pl->num_cmds = count_cmds(pl->prompt);
	pl->cmds = split_cmds(pl->prompt, pl->num_cmds);
	if (!pl->cmds)
		exit(1);
	return (0);
}

static bool	is_prompt_empty(const char *prompt)
{
	while (ft_isspace(*prompt))
		prompt++;
	return (!*prompt);
}

static int	count_cmds(const char *prompt)
{
	int	count;

	count = 1;
	while (*prompt)
	{
		if (*prompt == '|')
			count++;
		else if (*prompt == '\'' || *prompt == '"')
			prompt = ft_strchr(prompt + 1, *prompt);
		prompt++;
	}
	return (count);
}

static t_cmd	*split_cmds(char *prompt, int num_cmds)
{
	t_cmd *const	cmds = ft_calloc(num_cmds, sizeof(t_cmd));
	int				i;

	if (!cmds)
		return (NULL);
	i = -1;
	while (++i < num_cmds)
		ft_memset(cmds[i].pipe, -1, sizeof(int) * 2);
	cmds[0].cmd = prompt;
	i = 1;
	while (*prompt)
	{
		if (*prompt == '|')
		{
			*prompt = 0;
			cmds[i++].cmd = prompt + 1;
		}
		else if (*prompt == '\'' || *prompt == '"')
			prompt = ft_strchr(prompt + 1, *prompt);
		else if (ft_isspace(*prompt))
			*prompt = ' ';
		prompt++;
	}
	return (cmds);
}
