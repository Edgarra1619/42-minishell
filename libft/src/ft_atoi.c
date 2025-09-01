/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-albu <vde-albu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 14:20:23 by vde-albu          #+#    #+#             */
/*   Updated: 2025/06/12 16:21:36 by vde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include <limits.h>

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	num;

	while (ft_isspace(*nptr))
		nptr++;
	sign = 1;
	if (*nptr == '-' || *nptr == '+')
		if (*nptr++ == '-')
			sign = -1;
	num = 0;
	while (ft_isdigit(*nptr))
		num = num * 10 + *nptr++ - '0';
	return (num * sign);
}

int	ft_atoi_hex(const char *nptr)
{
	int	num;

	while (ft_isspace(*nptr))
		nptr++;
	num = 0;
	while (*nptr)
	{
		if (ft_isdigit(*nptr))
			num = num * 16 + *nptr++ - '0';
		else if (*nptr >= 'a' && *nptr <= 'f')
			num = num * 16 + 10 + *nptr++ - 'a';
		else if (*nptr >= 'A' && *nptr <= 'F')
			num = num * 16 + 10 + *nptr++ - 'A';
		else
			break ;
	}
	return (num);
}

int	ft_atoi_safe(int *const num_ptr, const char *str)
{
	long	num;
	int		sign;

	while (ft_isspace(*str))
		str++;
	sign = 1;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1;
	num = 0;
	while (*str)
	{
		if (!ft_isdigit(*str))
			return (1);
		if (num * sign > INT_MAX || num * sign < INT_MIN)
			return (1);
		num = num * 10 + *str++ - '0';
	}
	*num_ptr = num * sign;
	return (0);
}
