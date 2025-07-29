/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-albu <vde-albu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:07:14 by vde-albu          #+#    #+#             */
/*   Updated: 2025/04/07 12:26:27 by vde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*s1_ptr;
	const unsigned char	*s2_ptr;
	size_t				i;

	if (n == 0)
		return (0);
	s1_ptr = s1;
	s2_ptr = s2;
	i = 0;
	while (s1_ptr[i] == s2_ptr[i] && i + 1 < n)
		i++;
	return (s1_ptr[i] - s2_ptr[i]);
}
