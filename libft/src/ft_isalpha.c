/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-albu <vde-albu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 11:00:07 by vde-albu          #+#    #+#             */
/*   Updated: 2025/05/19 11:20:25 by vde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	isupper(const int c)
{
	return (c >= 'A' && c <= 'Z');
}

static int	islower(const int c)
{
	return (c >= 'a' && c <= 'z');
}

int	ft_isalpha(const int c)
{
	return (isupper(c) || islower(c));
}
