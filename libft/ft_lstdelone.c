/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-you <yael-you@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 10:29:35 by yael-you          #+#    #+#             */
/*   Updated: 2025/01/28 13:00:12 by yael-you         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

void ft_lstdelone(t_list *lst, void (*del)(void
*))
{
	if (!lst || !del)
		return ;
	del(lst->content);//liberamos contenido del nodo
	free(lst);
}