/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-you <yael-you@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 02:31:17 by yael-you          #+#    #+#             */
/*   Updated: 2025/01/28 12:58:29 by yael-you         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "libft.h"
void ft_lstiter(t_list *lst, void (*f)(void *))
{
    int i;
    i = 0;
    if (!lst || !f)
        return ;
     while (lst)
    {
        f(lst->content);
        lst = lst->next;
        i++;
    }
}  
