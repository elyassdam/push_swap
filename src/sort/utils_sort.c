/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-you <yael-you@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 07:59:54 by yael-you          #+#    #+#             */
/*   Updated: 2025/06/02 12:04:50 by yael-you         ###   ########.fr       */
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
int cost(t_stack *a, t_stack *b, int value)
{
    int moves_a;
    int couple;
    int moves_b;
    int cost;

    if (!a || !a->top || !b || !b->top)
        return (__INT_MAX__);

    // Buscamos la pareja correcta en A para insertar 'value'
    couple = find_couple(a, value);
    moves_a = get_moves_to_top(b, couple);

    // Movimientos para traer 'value' a la cima de B
    moves_b = get_moves_to_top(b, value);

    // Si ambos movimientos en la misma dirección (ambos positivos o ambos negativos)
    if ((moves_a >= 0 && moves_b >= 0) || (moves_a < 0 && moves_b < 0))
    {
        // Tomamos el mayor valor en módulo sin abs, usando comparación directa
        if (moves_a > moves_b)
            cost = moves_a;
        else
            cost = moves_b;
    }
    else
    {
        // Si están en direcciones opuestas sumamos movimientos en positivo
        if (moves_a < 0)
            moves_a = -moves_a;
        if (moves_b < 0)
            moves_b = -moves_b;
        cost = moves_a + moves_b;
    }
    return cost;
}

int	cheapest(t_stack *a, t_stack *b)
{
	t_list	*i;
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
	int		max_b;
	int		min_b;
	int		current_b_val;
	int		best_fit_val_b; // El valor en B que será la pareja
	int		best_diff;      // Para encontrar el "mayor de B menor que value_a"

	if (!b || !b->top) // B está vacía, no hay pareja (esto debería manejarse antes de llamar)
		return (0); // O un valor sentinel para error

	max_b = get_max(b);
	min_b = get_min(b);

	// Caso 1: value_a es el más pequeño o más grande de todos en B
	if (value_a < min_b)
		return (min_b); // Se insertará ANTES del mínimo de B
	if (value_a > max_b)
		return (min_b); // Se insertará ANTES del mínimo de B (luego se rotará B para ponerlo al final)

	
	best_fit_val_b = max_b; // Inicializamos con un valor grande
	best_diff = INT_MAX; // Diferencia positiva más pequeña (value_b - value_a > 0)

	i = b->top;
	while (i)
	{
		current_b_val = *(int *)i->content;
		if (current_b_val > value_a && (current_b_val - value_a) < best_diff)
		{
			best_diff = current_b_val - value_a;
			best_fit_val_b = current_b_val;
		}
		i = i->next;
	}
    // ft_printf("DEBUG: Pareja para %d en B es: %d\n", value_a, best_fit_val_b); // Solo para depuración
	return (best_fit_val_b); // Retorna el valor en B que es el menor > value_a
}

int get_moves_to_top(t_stack *stack, int value)
{
    t_list  *i;
    int     index;
    int     moves_up;
    int     moves_down;

    if (!stack || !stack->top)
        return (0); // Valor alto si stack vacío

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
    return (__INT_MAX__); // Valor alto si no encontrado
}
int find_target_pos_in_a(t_stack *a, int value_from_b)
{
    t_list *current_a_node;
 
    int     min_a;
    int     max_a;

    if (!a || !a->top)
        return (0);

    min_a = get_min(a);
    max_a = get_max(a);

    if (value_from_b < min_a || value_from_b > max_a)
    {
        return min_a;
    }

    current_a_node = a->top;
    while (current_a_node)
    {
        int current_a_val = *(int *)current_a_node->content;
        int next_a_val;

        if (current_a_node->next)
            next_a_val = *(int *)current_a_node->next->content;
        else
            next_a_val = *(int *)a->top->content;

        if (value_from_b > current_a_val && value_from_b < next_a_val)
        {
            return next_a_val;
        }
        current_a_node = current_a_node->next;
    }
    
    return min_a;
}
int	do_move_top(t_stack *a, t_stack *b)
{
	int cheap;
	int moves_a;
	int moves_b;
	int couple;

	cheap = cheapest(a, b);
	couple = find_couple(b, cheap);
	moves_a = get_moves_to_top(a, cheap);
	moves_b = get_moves_to_top(b, couple);

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
	//ft_printf("Después de rb: ");
	//ft_print_stack(b);

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
void	final_rotate(t_stack *a)
{
	int min_val;
	int moves;

	min_val = get_min(a);
	moves = get_moves_to_top(a, min_val);

	while (moves > 0)
	{
		ra(a);
		moves--;
	}
	while (moves < 0)
	{
		rra(a);
		moves++;
	}
}

int is_sorted(t_stack *stack)
{
    if (!stack || !stack->top)
        return (1);
    
    t_list *current = stack->top;
    while (current->next)
    {
        if (*(int *)current->content > *(int *)current->next->content)
            return (0);
        current = current->next;
    }
    return (1);
}


int cost_b_to_a(t_stack *a, t_stack *b, int value_b)
{
    int moves_a;
    int moves_b;
    int target_a;
    int cost;

    if (!a || !b || !b->top)
        return (__INT_MAX__);

    // Encontrar dónde debe ir value_b en A
    target_a = find_target_pos_in_a(a, value_b);
    
    // Movimientos para traer target_a al top de A
    moves_a = get_moves_to_top(a, target_a);
    
    // Movimientos para traer value_b al top de B
    moves_b = get_moves_to_top(b, value_b);

    // EXACTAMENTE la misma lógica que tu función cost()
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
    return cost;
}

// Función para encontrar el más barato de B (igual que tu cheapest() pero para B)
int cheapest_b_to_a(t_stack *a, t_stack *b)
{
    t_list  *i;
    int     cheapest_cost;
    int     cheapest_value;
    int     value;
    int     current_cost;

    if (!b || !b->top)
        return (0);
    
    i = b->top;
    cheapest_value = *(int *)i->content;
    cheapest_cost = cost_b_to_a(a, b, cheapest_value);
    
    while (i != NULL)
    {
        value = *(int *)i->content;
        current_cost = cost_b_to_a(a, b, value);
        if (current_cost < cheapest_cost)
        {
            cheapest_cost = current_cost;
            cheapest_value = value;
        }
        i = i->next;
    }
    return (cheapest_value);
}

// Función para hacer el movimiento B->A (igual que tu do_move_top() pero para B->A)
int do_move_b_to_a(t_stack *a, t_stack *b)
{
    int cheap_b;
    int moves_a;
    int moves_b;
    int target_a;

    cheap_b = cheapest_b_to_a(a, b);
    target_a = find_target_pos_in_a(a, cheap_b);
    moves_a = get_moves_to_top(a, target_a);
    moves_b = get_moves_to_top(b, cheap_b);

    // Rotaciones dobles (EXACTAMENTE igual que en do_move_top)
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
    
    // Rotaciones individuales (EXACTAMENTE igual que en do_move_top)
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
    
    pa(a, b);
    return (1);
}
