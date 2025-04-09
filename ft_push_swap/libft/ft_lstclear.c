/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-you <yael-you@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 02:32:49 by yael-you          #+#    #+#             */
/*   Updated: 2025/01/28 14:07:20 by yael-you         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void
*))
{
    t_list  *next_node;
    
    next_node = NULL;
	if (!lst || !del)
		return ;
	while (*lst)
	{
		next_node = (*lst)->next;
		del((*lst)->content);//liberamos contenido del nodo
		free(*lst);
        *lst = next_node;
	}
	*lst = (NULL);
}