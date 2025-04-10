/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* rules_2.c                                          :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: yael-you <yael-you@student.42.fr>          +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2025/04/10 12:58:15 by yael-you          #+#    #+#             */
/* Updated: 2025/04/10 13:45:00 by yael-you         ###   ########.fr       */
/* */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

void ra (t_stack *a)
{
    t_list *first;
    t_list *last;

    if (!a || !a->top || !a->top->next)
        return;
    a->size = ft_lstsize(a->top);
    first = a->top;
    last = a->top;
    while (last->next != NULL)
        last = last->next;
    a->top = first->next;
    last->next = first;
    first->next = NULL;
}

void rb (t_stack *b)
{
    t_list *first;
    t_list *last;

    if (!b || !b->top || !b->top->next)
        return;
    b->size = ft_lstsize(b->top);
    first = b->top;
    last = b->top;

    while (last->next != NULL)
        last = last->next;
    b->top = first->next;
    last->next = first;
    first->next = NULL;
}

void rr (t_stack *a, t_stack *b)
{
    ra(a);
    rb(b);
}

void rra (t_stack *a)
{
    t_list *first;
    t_list *last;
    t_list *before_last;

    if (!a || !a->top || !a->top->next)
        return;
    a->size = ft_lstsize(a->top);
    first = a->top;
    before_last = NULL;
    last = a->top;
    while (last->next != NULL)
    {
        before_last = last;
        last = last->next;
    }
    a->top = last;
    last->next = first;
    if (before_last != NULL)
        before_last->next = NULL;
    else
        first->next = NULL; // Si solo hay dos elementos
}

void rrb (t_stack *b)
{
    t_list *first;
    t_list *last;
    t_list *before_last;

    if (!b || !b->top || !b->top->next)
        return;
    b->size = ft_lstsize(b->top);
    first = b->top;
    before_last = NULL;
    last = b->top;
    while (last->next != NULL)
    {
        before_last = last;
        last = last->next;
    }
    b->top = last;
    last->next = first;
    if (before_last != NULL)
        before_last->next = NULL;
    else
        first->next = NULL; // Si solo hay dos elementos
}

void rrr (t_stack *a, t_stack *b)
{
    rra(a);
    rrb(b);
}