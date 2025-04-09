/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_01duplicates.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-you <yael-you@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 14:03:12 by yael-you          #+#    #+#             */
/*   Updated: 2025/04/03 14:52:52 by yael-you         ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "ft_push_swap.h"
#include <stdlib.h>

/* int main (int argc,char** argv){
	(void)argc;
	t_stack stack;
	if (argc < 2)
		return (0);

	stack.size = argc -1;
	while (argc > 0)
		stack.content->argv[stack.size]
		if (argv[i] == argv[i +1])
			exit (1);
	return (0);
}
 */
int	ft_check_duplicates(t_stack *stack)
{
	t_node	*i;
	t_node	*j;

	i = stack->top;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->value == j->value)
				return (1);
			j = j->next;
		}
		i = i->next;
	}
	return (0);
}
#include <limits.h>
#include <stdlib.h>

int	parse_args(t_stack *stack, int argc, char **argv)
{
	int	i;
	int	value;

	i = 1;
	while (i < argc)
	{
		if (!ft_isdigit(argv[i]))
			return (0);
		value = atoi(argv[i]);
		if (value < INT_MIN || value > INT_MAX)
			return (0);
		ft_lstadd_back(stack, (int)value);
		i++;
	}
	if (ft_check_duplicates(stack))
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack;
	int		i;
	int		value;

	if (argc < 2)
		return (0);
	i = 1;
	while (argv[i])
	{
		ft_split(argv[i]);
		value = ft_atoi(argv[i]);
		stack = ft_lstadd_back(stack, value);
		i++;
	}
	if (ft_check_duplicates(stack))
	{
		ft_lstclear(stack);
		ft_error();
	}
	if (!parse_args(&stack, argc, argv))
	{
		printf("Error\n");
		ft_lstclear(&stack);
		return (1);
	}
	ft_lstclear(stack);
	return (0);
}
void	swap(t_stack *swaped_stack)
{
	t_node	*i;
	t_node	*j;
	int		t;

	if (!swaped_stack || !swaped_stack->top || !swaped_stack->top->next)
		return ;
	swaped_stack->size = ft_lstsize(swaped_stack);
	if (swaped_stack->size <= 1)
		return ;
	i = swaped_stack->top;
	j = i->next;
	t = i->value;
	i->value = j->value;
	j->value = t;
}
void	ss(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ;
	if (a->size <= 1 || b->size <= 1)
		return ;
	swap(a);
	swap(b);
}

void	pa(t_stack *a, t_stack *b)
{
	t_node	*i;

	if (!b || !b->top)
		return ;
	a->size = ft_lstsize(a);
	if (a->size <= 1)
		return ;
	i = a->top;
	a->top = a->top->next;
	i->next = b->top;
	b->top = i;
}
void	pb(t_stack *a, t_stack *b)
{
	t_node	*i;

	if (!a || !a->top)
		return ;
	b->size = ft_lstsize(b);
	if (b->size <= 1)
		return ;
	i = b->top;
	b->top = b->top->next;
	i->next = a->top;
	a->top = i;
}

void ra (t_stack *a)
{
	t_node *first;
	t_node *last;
	int	i;
	
 	if (!a || !a->top || !a->top->next)
    	return;
	a->size = ft_lstsize(a);
	first = a->top;
	last = a->top;
	i = 1;
	while (i < a->size)
	{
		last = last->next;
		i ++;
	}
	a->top = first->next;
	last->next =  first;
	first->next = NULL;
}

void rb (t_stack *b)
{
	t_node *first;
	t_node *last;

	if (!b || !b->top || !b->top->next)
    	return;
	b->size = ft_lstsize(b);
	first = b->top;
	last = b->top;
	
	while (last->next != NULL)
	{
		last = last->next;
	}
	b->top = first->next;
	last->next =  first;
	first->next = NULL;
}

void rr (t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}

void rra (t_stack *a)
{
	t_node *first;
	t_node *last;
	int	i;
	
 	if (!a || !a->top || !a->top->next)
    	return;
	a->size = ft_lstsize(a);
	first = a->top;
	last = a->top;
	i = 1;
	while (i < a->size -1)
	{
		last = last->next;
		i ++;
	}
	a->top = last->next;
	first->next =  last;
	last->next = NULL;
}

