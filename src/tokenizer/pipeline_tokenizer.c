/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline_tokenizer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-albu <vde-albu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:48:23 by vde-albu          #+#    #+#             */
/*   Updated: 2025/09/25 16:22:15 by edgribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell/env.h>
#include <minishell/tokenizer.h>
#include <minishell/exit.h>
#include <libft.h>

#include <stdbool.h>

static int		count_cmds(const char *prompt);
static t_cmd	*split_cmds(char *prompt, int num_cmds);

int	tokenize_pipeline(t_pipeline *pl)
{
	char	*status;
	int		i;

	if (verify_prompt_syntax(pl->prompt))
	{
		get_env(NULL, NULL, NULL, &status);
		*status = 2;
		return (1);
	}
	pl->num_cmds = count_cmds(pl->prompt);
	pl->cmds = split_cmds(pl->prompt, pl->num_cmds);
	i = -1;
	while (++i < pl->num_cmds)
	{
		pl->cmds[i].pipes[0].source_fd = -1;
		pl->cmds[i].pipes[1].source_fd = -1;
		if (tokenize_cmd(pl->cmds + i))
			return (1);
	}
	return (0);
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
		error_exit(1);
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
