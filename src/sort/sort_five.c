/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-you <yael-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:30:38 by yael-you          #+#    #+#             */
/*   Updated: 2025/05/28 14:17:07 by yael-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

int get_max(t_stack *a)
{
    if (!a || !a->top)
    {
        return (__INT32_MAX__ * -1);
    }

    int     max_val;
    t_list  *current;

    max_val = *(int *)a->top->content;

    current = a->top;
    while (current != NULL)
    {
        if (current->content)
        {
            if (max_val < *(int *)current->content)
                max_val = *(int *)current->content;
        }
        current = current->next;
    }
    return (max_val);
}

int get_min(t_stack *a)
{
    if (!a || !a->top)
    {
        return (__INT32_MAX__);
    }

    int     min_val;
    t_list  *current;

    min_val = *(int *)a->top->content;

    current = a->top;
    while (current != NULL)
    {
        if (current->content)
        {
            if (min_val > *(int *)current->content)
                min_val = *(int *)current->content;
        }
        current = current->next;
    }
    return (min_val);
}

int get_pos(t_stack *a, int value)
{
	t_list *current = a->top;
	int pos = 0;
    while (current)
	{
		if (*(int *)current->content == value)
			return pos ;
		pos++;
		current = current->next;
	}
	return -1;
}
void sort_five(t_stack *a, t_stack *b)
{
    int min;
    int pos;
    int count = 0;

    while (count < 2)
    {
        min = get_min(a);
        pos = get_pos(a, min);
        if (pos <= (a->size / 2))
        {
            while (*(int *)a->top->content != min)
                ra(a);
        }
        else
        {
            while (*(int *)a->top->content != min)
                rra(a);
        }
        pb(a, b);
        count++;
    }

    sort_three(a); // ahora a tiene los 3 mayores

    if (*(int *)b->top->content < *(int *)b->top->next->content)
        sb(b); // asegurar que el menor sube primero

    pa(a, b);
    pa(a, b);
}

