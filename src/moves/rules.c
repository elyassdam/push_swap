/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* rules.c                                            :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: yael-you <yael-you@student.42.fr>          +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2025/04/10 12:54:23 by yael-you          #+#    #+#             */
/* Updated: 2025/04/10 13:40:00 by yael-you         ###   ########.fr       */
/* */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

void    swap(t_stack *swaped_stack)
{
    t_list  *i;
    t_list  *j;
    void    *temp_content;

    if (!swaped_stack || !swaped_stack->top || !swaped_stack->top->next)
        return ;
    swaped_stack->size = ft_lstsize(swaped_stack->top);
    if (swaped_stack->size <= 1)
        return ;
    i = swaped_stack->top;
    j = i->next;
    temp_content = i->content;
    i->content = j->content;
    j->content = temp_content;
}

void    ss(t_stack *a, t_stack *b)
{
    if (!a || !b)
        return ;
    a->size = ft_lstsize(a->top);
    b->size = ft_lstsize(b->top);
    if (a->size <= 1 || b->size <= 1)
        return ;
    swap(a);
    swap(b);
}

void    pa(t_stack *a, t_stack *b)
{
    t_list  *node_to_move;

    if (!b || !b->top)
        return ;

    node_to_move = b->top;
    b->top = b->top->next;
    node_to_move->next = a->top;
    a->top = node_to_move;

    a->size = ft_lstsize(a->top);
    b->size = ft_lstsize(b->top);
}

void    pb(t_stack *a, t_stack *b)
{
    t_list  *node_to_move;

    if (!a || !a->top)
        return ;

    node_to_move = a->top;
    a->top = a->top->next;
    node_to_move->next = b->top;
    b->top = node_to_move;

    a->size = ft_lstsize(a->top);
    b->size = ft_lstsize(b->top);
}

