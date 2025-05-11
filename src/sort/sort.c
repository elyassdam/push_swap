/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-you <yael-you@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 07:59:54 by yael-you          #+#    #+#             */
/*   Updated: 2025/05/11 08:02:40 by yael-you         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../includes/ft_push_swap.h"

void	push_two(t_stack *a, t_stack *b)
{
	if (!a || !a->top || !a->top->next)
		return ;
	pb(a, b);
	pb(a, b);
}
int	cost(t_stack *a, t_stack *b, int value)
{
	int	moves_a;
	int	couple;
	int	moves_b;
	int	cost;

	if (!a || !a->top || !b || !b->top)
		return (__INT_MAX__);
	moves_a = get_moves_to_top(a, value);
	couple = find_couple(b, value);
	moves_b = get_moves_to_top(b, couple);
	if ((moves_a >= 0 && moves_b >= 0) || (moves_a < 0 && moves_b < 0))
	{
		if (moves_a > moves_b)
			cost = moves_a;
		else
			cost = moves_b;
	}
	else
	{
		if (moves_a < 0)
			moves_a = -moves_a;
		if (moves_b < 0)
			moves_b = -moves_b;
		cost = moves_a + moves_b;
	}
	return (cost);
}
int	cheapest(t_stack *a, t_stack *b)
{
	t_list	*i;
	int		cheap;
	int		cheapest_cost;
	int		cheapest_value;
	int		value;
	int		current_cost;

	if (!a || !a->top)
		return (0);
	i = a->top;
	cheapest_value = *(int *)i->content;
	cheapest_cost = cost(a, b, cheapest_value);
	while (i != NULL)
	{
		value = *(int *)i->content;
		current_cost = cost(a, b, value);
		if (current_cost < cheapest_cost)
		{
			cheapest_cost = current_cost;
			cheapest_value = value;
		}
		i = i->next;
	}
	return (cheapest_value);
}
int	find_couple(t_stack *b, int value_a)
{
	t_list	*i;
	int		maxb;
	int		minb;
	int		value_b;
	int		diff;
	int		min_diff;
	int		best_match;

	best_match = 0;
	min_diff = __INT_MAX__;
	if (!b || !b->top)
		return (0);
	maxb = get_max(b);
	minb = get_min(b);
	if (value_a > maxb || value_a < minb)
		return (minb);
	best_match = minb;
	i = b->top;
	while (i != NULL)
	{
		value_b = *(int *)i->content;
		diff = value_a - value_b;
		if (diff > 0 && diff < min_diff)
		{
			min_diff = diff;
			best_match = value_b;
		}
		i = i->next;
	}
	return (best_match);
}

int	get_moves_to_top(t_stack *stack, int value)
{
	t_list	*i;
	int		index;
	int		moves_up;
	int		moves_down;

	if (!stack || !stack->top)
		return (-1);
	i = stack->top;
	index = 0;
	while (i != NULL)
	{
		if (*(int *)i->content == value)
		{
			moves_up = index;
			moves_down = stack->size - index;
			if (moves_up <= moves_down)
				return (moves_up);
			else
				return (-moves_down);
		}
		i = i->next;
		index++;
	}
	return (-1);
}
int	do_move_top(t_stack *a, t_stack *b)
{
	int cheap;
	int moves_a;
	int moves_b;
	int couple;

	moves_a = get_moves_to_top(a, cheap);
	moves_b = get_moves_to_top(b, couple);
	cheap = cheapest(a, b);
	couple = find_couple(b, cheap);
	// Rotacioens dobles
	while (moves_a > 0 && moves_b > 0)
	{
		rr(a, b);
		moves_a--;
		moves_b--;
	}
	while (moves_a < 0 && moves_b < 0)
	{
		rrr(a, b);
		moves_a++;
		moves_b++;
	}
	// Rotacioens individuales basandonos en el cost
	while (moves_a > 0)
	{
		ra(a);
		moves_a--;
	}
	while (moves_a < 0)
	{
		rra(a);
		moves_a++;
	}
	while (moves_b > 0)
	{
		rb(b);
		moves_b--;
	}
	while (moves_b < 0)
	{
		rrb(b);
		moves_b++;
	}
	pb(a, b);
	return (1);
}