/* ************************************************************************** */
/*                                                                            */
/*                                                      34op56546  :::      ::::::::   */
/*   ft_lstadd_back_swap.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-you <yael-you@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 13:23:56 by yael-you          #+#    #+#             */
/*   Updated: 2025/03/27 13:24:41 by yael-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "./libft"

void	ft_lstadd_back_swap(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	while ((*lst)->next != NULL)
		lst = &(*lst)->next;
	(*lst)->next = new;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
}