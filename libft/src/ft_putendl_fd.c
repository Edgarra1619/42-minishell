/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-albu <vde-albu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:44:01 by vde-albu          #+#    #+#             */
/*   Updated: 2025/05/13 12:01:12 by vde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putendl_fd(const char *s, const int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
