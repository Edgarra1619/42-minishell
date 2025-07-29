/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-albu <vde-albu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 14:16:07 by vde-albu          #+#    #+#             */
/*   Updated: 2025/04/24 11:33:30 by vde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	s_len;
	char			*new;

	s_len = ft_strlen(s);
	new = malloc(sizeof(char) * (s_len + 1));
	if (!new)
		return (NULL);
	new[s_len] = '\0';
	i = 0;
	while (i < s_len)
	{
		new[i] = f(i, s[i]);
		i++;
	}
	return (new);
}
