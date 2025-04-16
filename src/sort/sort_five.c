/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-you <yael-you@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:30:38 by yael-you          #+#    #+#             */
/*   Updated: 2025/04/16 14:31:02 by yael-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/ft_push_swap.h"
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
            while (a->top->content != max)
                ra(a);
        else
        while (a->top->content != max)
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
int get_max(t_stack *a)
{
    int max;
    t_list *i;

    i = a->top;
    max = i->content;
    while (i->next != NULL)
    {
        if (max < i->content)
            max = i->content;
        i = i->next;
    }
    return max;
}
int get_pos(t_stack *a, int value)
{
	t_list *current = a->top;
	int pos = 0;
    while (current)
	{
		if (current->content == value)
			return pos ;
		pos++;
		current = current->next;
	}
	return -1;
}
