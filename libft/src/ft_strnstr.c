/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-albu <vde-albu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:33:37 by vde-albu          #+#    #+#             */
/*   Updated: 2025/04/24 11:32:07 by vde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	little_len;
	size_t	i;
	size_t	j;

	if (!*little)
		return ((char *) big);
	little_len = ft_strlen(little);
	i = 0;
	while (big[i] && i + little_len <= len)
	{
		if (big[i] == *little)
		{
			j = 0;
			while (big[i + j] && little[j] && big[i + j] == little[j])
				j++;
			if (j == little_len)
				return ((char *) &big[i]);
		}
		i++;
	}
	return (NULL);
}
