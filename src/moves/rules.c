/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* rules.c                                            :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: yael-you <yael-you@student.42.fr>          +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2025/04/10 12:54:23 by yael-you          #+#    #+#             */
/* Updated: 2025/04/10 16:31:00 by yael-you         ###   ########.fr       */
/* */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

void    sa(t_stack *a)
{
    t_list  *i;
    t_list  *j;
    void    *temp_content;

    if (!a || !a->top || !a->top->next)
        return ;
    a->size = ft_lstsize(a->top);
    if (a->size <= 1)
        return ;
    i = a->top;
    j = i->next;
    temp_content = i->content;
    i->content = j->content;
    j->content = temp_content;
    ft_printf("sa\n");
}

void    sb(t_stack *b)
{
    t_list  *i;
    t_list  *j;
    void    *temp_content;

    if (!b || !b->top || !b->top->next)
        return ;
    b->size = ft_lstsize(b->top);
    if (b->size <= 1)
        return ;
    i = b->top;
    j = i->next;
    temp_content = i->content;
    i->content = j->content;
    j->content = temp_content;
    ft_printf("sb\n");
}

void    ss(t_stack *a, t_stack *b)
{
    if (!a || !b)
        return ;
    a->size = ft_lstsize(a->top);
    b->size = ft_lstsize(b->top);
    if (a->size <= 1 || b->size <= 1)
        return ;
    sa(a);
    sb(b);
    ft_printf("ss\n");
}

void    pa(t_stack *a, t_stack *b)
{
    t_list  *i;

    if (!b || !b->top)
        return ;

    i = b->top;
    b->top = b->top->next;
    i->next = a->top;
    a->top = i;

    a->size = ft_lstsize(a->top);
    b->size = ft_lstsize(b->top);
    ft_printf("pa\n");
}

void    pb(t_stack *a, t_stack *b)
{
    t_list  *i;

    if (!a || !a->top)
        return ;

    i = a->top;
    a->top = a->top->next;
    i->next = b->top;
    b->top = i;

    a->size = ft_lstsize(a->top);
    b->size = ft_lstsize(b->top);
    ft_printf("pb\n");
}