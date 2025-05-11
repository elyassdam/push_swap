/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-you <yael-you@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:30:38 by yael-you          #+#    #+#             */
/*   Updated: 2025/05/11 08:00:40 by yael-you         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

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
