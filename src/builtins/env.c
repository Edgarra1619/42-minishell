/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-albu <vde-albu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:48:59 by vde-albu          #+#    #+#             */
/*   Updated: 2025/09/23 14:49:00 by vde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell/env.h>
#include <libft.h>

int	env_builtin(void)
{
	char	**envp;

	get_env(NULL, NULL, &envp, NULL);
	while (*envp)
	{
		if (ft_strchr(*envp, '='))
			ft_putendl_fd(*envp, 1);
		envp++;
	}
	return (0);
}
