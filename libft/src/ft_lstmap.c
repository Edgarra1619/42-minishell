/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-albu <vde-albu@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 10:43:58 by vde-albu          #+#    #+#             */
/*   Updated: 2025/06/06 14:33:39 by vde-albu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*node;
	void	*node_content;

	if (!f)
		return (NULL);
	new = NULL;
	while (lst)
	{
		node_content = f(lst->content);
		node = ft_lstnew(node_content);
		if (!node || !node_content)
		{
			if (del)
				del(node_content);
			ft_lstdelone(node, del);
			ft_lstclear(&new, del);
			return (NULL);
		}
		ft_lstadd_back(&new, node);
		lst = lst->next;
	}
	return (new);
}
