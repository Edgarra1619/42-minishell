/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-albu <vde-albu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 13:13:13 by vde-albu          #+#    #+#             */
/*   Updated: 2025/04/24 11:31:02 by vde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*dest_ptr;
	const unsigned char	*src_ptr;
	size_t				i;

	if (!dest && !src)
		return (dest);
	if (dest < src)
		ft_memcpy(dest, src, n);
	else
	{
		dest_ptr = dest;
		src_ptr = src;
		i = n;
		while (i)
		{
			dest_ptr[i - 1] = src_ptr[i - 1];
			i--;
		}
	}
	return (dest);
}
