/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-albu <vde-albu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 09:56:41 by vde-albu          #+#    #+#             */
/*   Updated: 2025/04/05 11:10:29 by vde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	b;
	size_t			i;

	ptr = s;
	b = c;
	i = 0;
	while (i < n)
	{
		ptr[i] = b;
		i++;
	}
	return (s);
}
