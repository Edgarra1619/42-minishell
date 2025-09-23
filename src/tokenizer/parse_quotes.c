/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgribei <edgribei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:47:16 by edgribei          #+#    #+#             */
/*   Updated: 2025/09/23 14:47:18 by edgribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell/exit.h>
#include <minishell/tokenizer.h>

#include <libft.h>
#include <stdbool.h>

int	parse_quotes(char **arg, char **str, bool dquote)
{
	char *const	end = ft_strchr(*str, '\'' - 5 * dquote);

	*end = 0;
	if (!dquote)
	{
		ft_strappend(arg, *str);
		*end = '\'';
		*str = end + 1;
		return (!*arg);
	}
	expand_str(arg, str);
	*end = '"';
	*str = end + 1;
	return (!*arg);
}
