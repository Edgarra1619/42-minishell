/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-albu <vde-albu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:48:31 by vde-albu          #+#    #+#             */
/*   Updated: 2025/09/23 14:48:34 by vde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell/env.h>
#include <minishell/error.h>
#include <libft.h>

int	unset_builtin(char **argv, bool print_output)
{
	int	ret;

	ret = 0;
	while (*++argv)
	{
		if (!is_valid_key(*argv))
		{
			if (print_output)
				print_var_error("unset", *argv, "not a valid identifier");
			ret = 1;
		}
		remove_var(*argv);
	}
	return (ret);
}
