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
