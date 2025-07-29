/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-albu <vde-albu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 10:19:21 by vde-albu          #+#    #+#             */
/*   Updated: 2025/04/24 11:33:02 by vde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	s1_len;
	size_t	start;
	size_t	end;
	size_t	len;
	char	*new;

	s1_len = ft_strlen(s1);
	start = 0;
	while (start < s1_len && ft_strchr(set, s1[start]))
		start++;
	end = 0;
	while (end < s1_len && ft_strchr(set, s1[s1_len - end - 1]))
		end++;
	if (start + end < s1_len)
		len = s1_len - start - end;
	else
		len = 0;
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	ft_strlcpy(new, &s1[start], len + 1);
	return (new);
}
