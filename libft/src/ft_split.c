/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-albu <vde-albu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 10:43:54 by vde-albu          #+#    #+#             */
/*   Updated: 2025/04/24 11:33:09 by vde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

static unsigned int	count_strings(const char *s, char c)
{
	unsigned int	i;
	unsigned int	in_string;
	unsigned int	count;

	i = 0;
	in_string = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			in_string = 0;
		else if (!in_string)
		{
			in_string = 1;
			count++;
		}
		i++;
	}
	return (count);
}

static char	*get_string(const char *s, char c)
{
	unsigned int	i;
	char			*string;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	string = malloc(sizeof(char) * (i + 1));
	if (!string)
		return (NULL);
	ft_strlcpy(string, s, i + 1);
	return (string);
}

void	*free_split(char **split)
{
	unsigned int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

char	**ft_split(const char *s, char c)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	in_string;
	char			**strings;

	strings = ft_calloc(sizeof(char *), count_strings(s, c) + 1);
	i = 0;
	j = 0;
	in_string = 0;
	while (strings && s[i])
	{
		if (s[i] == c)
			in_string = 0;
		else if (!in_string)
		{
			in_string = 1;
			strings[j] = get_string(&s[i], c);
			if (!strings[j])
				return (free_split(strings));
			j++;
		}
		i++;
	}
	return (strings);
}
