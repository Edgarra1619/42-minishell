/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_tokenizer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgribei <edgribei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:46:41 by edgribei          #+#    #+#             */
/*   Updated: 2025/09/23 14:46:46 by edgribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell/env.h>
#include <minishell/exit.h>
#include <minishell/tokenizer.h>
#include <minishell/types.h>
#include <libft.h>

#include <stdbool.h>

int	tokenize_cmd(t_cmd *cmd)
{
	int	argc;

	argc = 0;
	cmd->argv = ft_calloc(sizeof(char *), argc + 2);
	while (*(cmd->cmd))
	{
		if (parse_next_special(&(cmd->argv), &argc, cmd, true))
			return (1);
	}
	return (0);
}

int	parse_next_special(char ***arg, int *argc, t_cmd *cmd, bool parse_spaces)
{
	char	*tmp;

	tmp = find_next_special(cmd->cmd);
	if (*tmp == '<' || *tmp == '>')
		return (parse_redir(*arg + *argc, cmd));
	if (tmp != cmd->cmd && append_args(*arg + *argc, cmd->cmd, tmp))
		clear_exit(1);
	cmd->cmd = tmp + (*tmp != '\0');
	if (ft_isspace(*tmp))
	{
		if (parse_spaces)
			return (parse_whtspc(argc, arg, &(cmd->cmd)));
		else
			return (0);
	}
	if (*tmp == '\'' || *tmp == '"')
		return (parse_quotes(*arg + *argc, &cmd->cmd, *tmp == '"'));
	if (*tmp == '$')
		return (parse_expans(argc, arg, &(cmd->cmd), false));
	return (0);
}

int	append_args(char **arg, char *str, char *end)
{
	const char	tmp = *end;

	*end = 0;
	ft_strappend(arg, str);
	*end = tmp;
	return (!*arg);
}

char	*find_next_special(char *str)
{
	while (*str)
	{
		if (*str == '$' || *str == ' ' || *str == '\'' || *str == '"'
			|| *str == '<' || *str == '>')
			return (str);
		str++;
	}
	return (str);
}
