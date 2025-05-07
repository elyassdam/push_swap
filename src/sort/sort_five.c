/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-you <yael-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:30:38 by yael-you          #+#    #+#             */
/*   Updated: 2025/05/07 17:45:04 by yael-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

int get_max(t_stack *a)
{
    if (!a || !a->top)
        return 0;
    int max;
    t_list *i;

    i = a->top->next;
    max = *(int *)i->content;
    while (i != NULL)
    {
        if (max < *(int *) i->content)
            max = *(int *) i->content;
        i = i->next;
    }
    return max;
}
int get_min(t_stack *a)
{
    if (!a || !a->top)
        return 0;
    int min;
    t_list *i;
    i = a->top->next;
    min = *(int *)i->content;
    while (i != NULL)
    {
        if (min > *(int *) i->content)
            min = *(int *) i->content;
        i = i->next;
    }
    return min;
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
    int count;
    int pos;
    int max;

    count = 0;
    while (count < 2)
    {
        max = get_max(a);
        pos = (get_pos(a, max));
        if (pos <= (ft_lstsize(a->top)/2))
            while (*(int *)a->top->content != max)
                ra(a);
        else
        while (*(int *)a->top->content != max)
            rra(a);
        pb (a,b);
        count ++;
    }
    sort_three(a);
    sb(b);
    pa(a,b);
    ra(a);
    pa(a,b);
    ra(a);
}
void push_two(t_stack *a, t_stack *b)
{
    if (!a || !a->top || !a->top->next)
        return;
    pb(a,b);
    pb(a,b);
}
void cost(t_stack *a, t_stack *b, int value)
{     if (!a || !a->top || !b || !b->top)
        return __INT_MAX__; 
    if ()
        






    
}
void find_couple(t_stack *b, int value_a)
{
    t_list *i;
    int maxb;
    int minb;
    int value_b;
    int diff;
    int min_diff;
    int best_match;
    
    best_match = 0;
    min_diff = __INT_MAX__;
    if (!b || !b->top)
        return 0;
    maxb = get_max(b);
    minb = get_min(b);
    if (value_a > maxb || value_a < minb)
        return minb;
    best_match = minb;
    i = b->top;
    while(i != NULL)
    {
        value_b = *(int *)i->content;
        diff = value_a -value_b;
        if (diff > 0 && diff < min_diff)
        {   min_diff = diff;
            best_match = value_b;
        }
        i = i->next;
    }
    return best_match;
}
  
int get_moves_to_top(t_stack *stack, int value) {
    if (!stack || !stack->top)
        return -1;
    t_list *i; 
    int index;
    int moves_up;
    int moves_down;
    i = stack->top;
    index = 0;
    while (i != NULL)
    {
        if (*(int *)i->content == value)
        {
            moves_up = index;
            moves_down = stack->size - index; 
            if (moves_up <= moves_down)
                return moves_up;
            else 
                return -moves_down;
        }
        i = i->next;
        index ++;
    }
    return -1;
}
