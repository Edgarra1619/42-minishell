/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   syntax.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-albu <vde-albu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:47:48 by vde-albu          #+#    #+#             */
/*   Updated: 2025/09/25 16:36:30 by edgribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell/error.h>
#include <libft.h>

#include <stdbool.h>

static int	verify_cmd_syntax(const char **cmd);
static int	verify_redir_syntax(const char **redir);
static int	verify_quote_syntax(const char **quote);

bool	is_prompt_empty(const char *prompt)
{
	while (ft_isspace(*prompt))
		prompt++;
	return (!*prompt);
}

int	verify_prompt_syntax(const char *prompt)
{
	while (true)
	{
		if (verify_cmd_syntax(&prompt))
			return (1);
		if (!*prompt)
			return (0);
		prompt++;
	}
}

static int	verify_cmd_syntax(const char **cmd)
{
	bool	has_cmd;

	has_cmd = false;
	while (**cmd && **cmd != '|')
	{
		if (!has_cmd && !ft_isspace(**cmd))
			has_cmd = true;
		if ((**cmd == '<' || **cmd == '>') && verify_redir_syntax(cmd))
			return (1);
		else if ((**cmd == '\'' || **cmd == '"') && verify_quote_syntax(cmd))
			return (1);
		(*cmd)++;
	}
	if (!has_cmd)
		return (print_syntax_error("empty command"));
	return (0);
}

static int	verify_redir_syntax(const char **redir)
{
	if ((*redir)[0] == (*redir)[1]
		|| ((*redir)[0] == '<' && (*redir)[1] == '>'))
		(*redir)++;
	(*redir)++;
	while (ft_isspace(**redir))
		(*redir)++;
	if (ft_memchr("<>|\0", **redir, 4))
		return (print_syntax_error("incomplete redirection"));
	return (0);
}

static int	verify_quote_syntax(const char **quote)
{
	*quote = ft_strchr(*quote + 1, **quote);
	if (!*quote)
		return (print_syntax_error("unclosed quote"));
	return (0);
}
