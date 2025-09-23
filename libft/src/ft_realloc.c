/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edgribei <edgribei@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 15:01:42 by edgribei          #+#    #+#             */
/*   Updated: 2025/09/23 15:01:43 by edgribei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

void	*ft_realloc(void *old, size_t old_size, size_t new_size)
{
	void *const	ptr = malloc(new_size);

	if (ptr)
	{
		ft_memcpy(ptr, old, old_size);
		free(old);
	}
	return (ptr);
}
