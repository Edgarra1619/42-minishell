/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strappend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgribei <edgribei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 15:01:47 by edgribei          #+#    #+#             */
/*   Updated: 2025/09/23 15:01:49 by edgribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

char	*ft_strappend(char **str1, const char *str2)
{
	char	*str;

	if (str2 == NULL)
		return (*str1);
	if (*str1)
		str = ft_strjoin(*str1, str2);
	else
		str = ft_strdup(str2);
	free(*str1);
	*str1 = str;
	return (str);
}
