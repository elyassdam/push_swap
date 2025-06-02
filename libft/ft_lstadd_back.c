
/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-you <yael-you@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 02:34:36 by yael-you          #+#    #+#             */
/*   Updated: 2025/01/28 13:59:03 by yael-you         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

void ft_lstadd_back(t_list **lst, t_list *new)
{    
	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{    *lst = new;
		return ;
	}
	while ((*lst)->next != NULL)
		lst = &(*lst)->next;
	(*lst)->next = new;
}