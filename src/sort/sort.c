/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-you <yael-you@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 15:58:22 by yael-you          #+#    #+#             */
/*   Updated: 2025/05/12 17:17:26 by yael-you         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"

void	sort(t_stack *a, t_stack *b)
{
    int first_value = *(int *)a->top->content;
    int second_value = *(int *)a->top->next->content;
	if (a->size == 2)
	{
       
		if (first_value > second_value)
			sa(a);
		return;
	}
	if (a->size == 3)
	{
		sort_three(a);
		return;
	}

	push_two(a, b); // Mandamos 2 a B para empezar

	if (a->size == 3)
		sort_three(a);

	// Mientras A tenga elementos, movemos los más baratos
	while (a->size > 0)
		do_move_top(a, b);

	// Colocamos el mínimo en el top de B para subirlo bien a A
	int min = get_min(b);
	int moves = get_moves_to_top(b, min);
	while (moves > 0)
	{
		rb(b);
		moves--;
	}
	while (moves < 0)
	{
		rrb(b);
		moves++;
	}

	// Pasamos todos los elementos de vuelta a A
	while (b->size > 0)
		pa(a, b);
}
