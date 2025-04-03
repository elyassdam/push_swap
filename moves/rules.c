/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-you <yael-you@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 20:16:33 by yael-you          #+#    #+#             */
/*   Updated: 2025/04/03 20:25:17 by yael-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include <unistd.h>

void	swap(t_stack *swaped_stack)
{
	t_node	*i;
	t_node	*j;
	int		t;

	if (!swaped_stack || !swaped_stack->top || !swaped_stack->top->next)
		return ;
	swaped_stack->size = ft_lstsize(swaped_stack);
	if (swaped_stack->size <= 1)
		return ;
	i = swaped_stack->top;
	j = i->next;
	t = i->value;
	i->value = j->value;
	j->value = t;
}
void	ss(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ;
	if (a->size <= 1 || b->size <= 1)
		return ;
	swap(a);
	swap(b);
}

void	pa(t_stack *a, t_stack *b)
{
	t_node	*i;

	if (!b || !b->top)
		return ;
	a->size = ft_lstsize(a);
	if (a->size <= 1)
		return ;
	i = a->top;
	a->top = a->top->next;
	i->next = b->top;
	b->top = i;
}
void	pb(t_stack *a, t_stack *b)
{
	t_node	*i;

	if (!a || !a->top)
		return ;
	b->size = ft_lstsize(b);
	if (b->size <= 1)
		return ;
	i = b->top;
	b->top = b->top->next;
	i->next = a->top;
	a->top = i;
}

void ra (t_stack *a)
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
	while (i < a->size)
	{
		last = last->next;
		i ++;
	}
	a->top = first->next;
	last->next =  first;
	first->next = NULL;
}