/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-albu <vde-albu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 13:14:14 by vde-albu          #+#    #+#             */
/*   Updated: 2025/06/17 12:22:00 by vde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include <libft.h>

static int	count_digits(long n)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(const int n)
{
	long		num;
	const int	neg = n < 0;
	int			digits;
	int			i;
	char		*str;

	num = n;
	if (neg)
		num = -num;
	digits = count_digits(num);
	str = malloc(sizeof(char) * (digits + neg + 1));
	if (!str)
		return (NULL);
	str[digits + neg] = '\0';
	if (neg)
		str[0] = '-';
	i = digits + neg;
	while (--i >= neg)
	{
		str[i] = '0' + (num % 10);
		num /= 10;
	}
	return (str);
}

size_t	ft_itoa_cpy(char *const str, const int n)
{
	long		num;
	const int	neg = n < 0;
	int			digits;
	int			i;

	num = n;
	if (neg)
		num = -num;
	digits = count_digits(num);
	str[digits + neg] = '\0';
	if (neg)
		str[0] = '-';
	i = digits + neg;
	while (--i >= neg)
	{
		str[i] = '0' + (num % 10);
		num /= 10;
	}
	return (neg + digits);
}
