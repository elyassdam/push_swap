/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-you <yael-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 16:59:27 by yael-you          #+#    #+#             */
/*   Updated: 2025/05/12 17:01:50 by yael-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

  #include "../includes/ft_push_swap.h"

void sort_three(t_stack *a)
{
    int first;
    int second;
    int third;

    if (!a || !a->top || !a->top->next || !a->top->next->next)
        return;

    first = *(int *)a->top->content;
    second = *(int *)a->top->next->content;
    third = *(int *)a->top->next->next->content;

    if (first > second && second > third)
    {
        sa(a);
        rra(a);
    }
    else if (first > second && second < third && first < third)
        sa(a);
    else if (first > second && second < third && first > third)
        ra(a);
    else if (first < second && second > third && first > third)
        rra(a);
    else if (first < second && second > third && first < third)
    {
        sa(a);
        ra(a);
    }
}

