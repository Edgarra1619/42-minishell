/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-albu <vde-albu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 11:10:20 by vde-albu          #+#    #+#             */
/*   Updated: 2025/04/14 15:28:41 by vde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*last;

	i = 0;
	last = NULL;
	while (s[i])
	{
		if ((unsigned char) s[i] == (unsigned char) c)
			last = (char *) &s[i];
		i++;
	}
	if ((unsigned char) c == '\0')
		return ((char *) &s[i]);
	return (last);
}
