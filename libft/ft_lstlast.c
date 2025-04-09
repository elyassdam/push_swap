/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-you <yael-you@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 02:29:06 by yael-you          #+#    #+#             */
/*   Updated: 2025/01/28 13:03:27 by yael-you         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"

t_list *ft_lstlast(t_list *lst)
{
    if (!lst)
        return NULL;
    while (lst->next)
        lst = lst->next;
    return (lst);
}