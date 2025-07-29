/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-albu <vde-albu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:46:51 by vde-albu          #+#    #+#             */
/*   Updated: 2025/04/07 12:28:54 by vde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*s_ptr;
	unsigned char		byte;
	size_t				i;

	s_ptr = s;
	byte = c;
	i = 0;
	while (i < n)
	{
		if (s_ptr[i] == byte)
			return ((void *) &s[i]);
		i++;
	}
	return (NULL);
}
