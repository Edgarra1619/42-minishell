#include <minishell/tokenizer.h>
#include <libft.h>

static int	is_prompt_empty(const char *prompt);

int	split_cmds(char *prompt)
{
	int	count;

	if (is_prompt_empty(prompt))
		return (0);
	if (verify_prompt_syntax(prompt))
		return (-1);
	count = 1;
	while (*prompt)
	{
		if (*prompt == '|')
		{
			*prompt = 0;
			count++;
		}
		else if (*prompt == '\'' || *prompt == '"')
			prompt = ft_strchr(prompt + 1, *prompt);
		else if (ft_isspace(*prompt))
			*prompt = ' ';
		prompt++;
	}
	return (count);
}

static int	is_prompt_empty(const char *prompt)
{
	while (ft_isspace(*prompt))
		prompt++;
	return (!*prompt);
}
