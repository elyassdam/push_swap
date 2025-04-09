/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-you <yael-you@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 11:26:10 by yael-you          #+#    #+#             */
/*   Updated: 2025/01/28 14:19:57 by yael-you         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *),void (*del)(void *))
{
	t_list *node2;
	t_list *lst2;
	void *content2;
		
	lst2 = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		content2 = f(lst->content);
		if (!content2)
		{
				ft_lstclear(&lst2, del);
				return (NULL);
		}

		{	
			node2 = ft_lstnew(content2);
			if(!node2)
			{
				del(content2);
				ft_lstclear(&lst2, del);
				return (NULL);
			}
			ft_lstadd_back(&lst2,node2);
			lst = lst->next;
		}
	}
	return (lst2);  
}
/*	t_list *node2;
	t_list *lst2;
	t_list *new_node;
	void *content2;
		
	lst2 = NULL;
	new_node = lst;
	if (!lst || !f || !del)
		return (NULL);
	while (new_node)
	{	
		content2 = f(new_node->content);
		node2 = ft_lstnew(content2);
		if(!node2)
		{
			del(content2);
			ft_lstclear(&lst2, del);
			return (NULL);
		}
		ft_lstadd_back(&lst2, node2);
		new_node = new_node->next;
	}
	return (lst2);
}*/