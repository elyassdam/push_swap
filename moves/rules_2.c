/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-you <yael-you@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 20:16:37 by yael-you          #+#    #+#             */
/*   Updated: 2025/04/03 20:25:22 by yael-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_push_swap.h"
#include <unistd.h>

void rb (t_stack *b)
{
	t_node *first;
	t_node *last;

	if (!b || !b->top || !b->top->next)
    	return;
	b->size = ft_lstsize(b);
	first = b->top;
	last = b->top;
	
	while (last->next != NULL)
	{
		last = last->next;
	}
	b->top = first->next;
	last->next =  first;
	first->next = NULL;
}

void rr (t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}

void rra (t_stack *a)
{
	t_node *first;
	t_node *last;
	int	i;
	
 	if (!a || !a->top || !a->top->next)
    	return;
	a->size = ft_lstsize(a);
	first = a->top;
	last = a->top;
	i = 1;
	while (i < a->size -1)
	{
		last = last->next;
		i ++;
	}
	a->top = last->next;
	first->next =  last;
	last->next = NULL;
}

