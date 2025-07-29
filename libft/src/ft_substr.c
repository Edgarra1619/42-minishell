/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-albu <vde-albu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:44:33 by vde-albu          #+#    #+#             */
/*   Updated: 2025/04/24 11:32:41 by vde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	size_t	substr_len;
	char	*substr;

	s_len = ft_strlen(s);
	if (start > s_len)
		return (ft_calloc(1, sizeof(char)));
	if (start + len > s_len)
		substr_len = s_len - start;
	else
		substr_len = len;
	substr = malloc(sizeof(char) * (substr_len + 1));
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, &s[start], substr_len + 1);
	return (substr);
}
