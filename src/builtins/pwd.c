/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-albu <vde-albu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:48:55 by vde-albu          #+#    #+#             */
/*   Updated: 2025/09/23 14:48:56 by vde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include <unistd.h>
#include <limits.h>
#include <stdbool.h>

int	pwd_builtin(const bool print_output)
{
	char	buffer[PATH_MAX];

	if (getcwd(buffer, PATH_MAX))
	{
		if (print_output)
			ft_putendl_fd(buffer, 1);
		return (0);
	}
	return (1);
}
