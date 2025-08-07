#include <libft.h>
#include <stdlib.h>

char	*ft_strappend(char **str1, const char *str2)
{
	char	*str;

	str = ft_strjoin(*str1, str2);
	free(*str1);
	*str1 = str;
	return (str);
}
