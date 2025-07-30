/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-albu <vde-albu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:45:53 by vde-albu          #+#    #+#             */
/*   Updated: 2025/04/04 20:54:03 by vde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		++i;
	return (i);
}

size_t	ft_strlen_delim(const char *s, const char delim)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != delim)
		++i;
	return (i);
}
