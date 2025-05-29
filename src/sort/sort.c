 #include "../includes/ft_push_swap.h"

/*  void    sort(t_stack *a, t_stack *b)
{
    if (a->size == 2)
    {
        if (*(int *)a->top->content > *(int *)a->top->next->content)
            sa(a);
        return;
    }
    if (a->size == 3)
    {
        sort_three(a);
        return;
    }

    while (a->size > 3)
    {
        do_move_top(a, b);
    }

    sort_three(a);

    if (!b || b->size == 0)
    {
        final_rotate(a);
        return;
    }

    while (b->size > 0)
    {
        int min_val_b = get_min(b);
        int moves_to_min_b = get_moves_to_top(b, min_val_b);

        while (*(int *)b->top->content != min_val_b)
        {
            if (moves_to_min_b > 0)
            {
                rb(b);
                moves_to_min_b--;
            }
            else
            {
                rrb(b);
                moves_to_min_b++;
            }
        }
        pa(a, b);
    }

    final_rotate(a);
}  */
 /* void    sort(t_stack *a, t_stack *b)
{

    if (a->size <= 1) 
        return;
    if (a->size == 2)
    {
        if (*(int *)a->top->content > *(int *)a->top->next->content)
            sa(a);
        return;
    }
    if (a->size == 3)
    {
        sort_three(a);
        return;
    }
    
    if (a->size == 5) 
    {
        sort_five(a, b);
        return;
    }

 
    pb(a, b);
    pb(a, b);

    while (a->size > 3)
    {
        do_move_top(a, b); // do_move_top ya calcula el más barato y lo empuja
    }

    sort_three(a);

 

    while (b->size > 0)
    {
        
        int max_val_b = get_max(b); // Asumiendo que get_max funciona bien
        int moves_to_max_b = get_moves_to_top(b, max_val_b);

        // Rotar B para traer el max_val_b a la cima
        while (*(int *)b->top->content != max_val_b)
        {
            if (moves_to_max_b > 0) // Rotar hacia arriba
            {
                rb(b);
                moves_to_max_b--;
            }
            else 
            {
                rrb(b);
                moves_to_max_b++;
            }
        }
        
        pa(a, b);
    }

  
    final_rotate(a);
} */
void    sort(t_stack *a, t_stack *b)
{
    // Casos base (ESTO NO CAMBIA)
    if (a->size <= 1)
        return;
    if (a->size == 2)
    {
        if (*(int *)a->top->content > *(int *)a->top->next->content)
            sa(a);
        return;
    }
    if (a->size == 3)
    {
        sort_three(a);
        return;
    }

    if (a->size == 5)
    {
        sort_five(a, b);
        return;
    }

    // Fase de empuje inicial (ESTO NO CAMBIA)
    pb(a, b);
    pb(a, b);

    // Bucle principal para empujar elementos de A a B (ESTO NO CAMBIA)
    while (a->size > 3)
    {
        do_move_top(a, b); // do_move_top ya calcula el más barato y lo empuja
    }

    // Ordenar los 3 elementos restantes en A (ESTO NO CAMBIA)
    sort_three(a);
    // Aquí se reemplaza tu bucle 'while (b->size > 0)' anterior
   while (b->size > 0)
    {
 

        int     cheapest_val_b = 0;
        int     min_total_moves = INT_MAX; // Usar INT_MAX de <limits.h>
        t_list  *current_b_node = b->top;

        while (current_b_node)
        {
            int val_b = *(int *)current_b_node->content;

            int moves_b_to_top = get_moves_to_top(b, val_b);
            int target_val_in_a = find_target_pos_in_a(a, val_b);
            int moves_a_to_target = get_moves_to_top(a, target_val_in_a);

            int current_total_moves;
            if ((moves_a_to_target >= 0 && moves_b_to_top >= 0) || (moves_a_to_target < 0 && moves_b_to_top < 0))
            {
                current_total_moves = (abs(moves_a_to_target) > abs(moves_b_to_top)) ? abs(moves_a_to_target) : abs(moves_b_to_top);
            }
            else
            {
                current_total_moves = abs(moves_a_to_target) + abs(moves_b_to_top);
            }

            if (current_total_moves < min_total_moves)
            {
                min_total_moves = current_total_moves;
                cheapest_val_b = val_b;
            }
            current_b_node = current_b_node->next;
        }
       
        // Volver a calcular los movimientos finales para el elemento elegido
        // (Esto es necesario porque la pila A o B pudieron cambiar ligeramente en el bucle interno)
        int final_moves_a = get_moves_to_top(a, find_target_pos_in_a(a, cheapest_val_b));
        int final_moves_b = get_moves_to_top(b, cheapest_val_b);


        // Realizar rotaciones dobles
        while (final_moves_a > 0 && final_moves_b > 0) { rr(a, b); final_moves_a--; final_moves_b--; }
        while (final_moves_a < 0 && final_moves_b < 0) { rrr(a, b); final_moves_a++; final_moves_b++; }

        // Realizar rotaciones individuales
        while (final_moves_a > 0) { ra(a); final_moves_a--; }
        while (final_moves_a < 0) { rra(a); final_moves_a++; }
        while (final_moves_b > 0) { rb(b); final_moves_b--; }
        while (final_moves_b < 0) { rrb(b); final_moves_b++; }

        
        pa(a, b);
      
    }
    final_rotate(a);
    // Rotación final de A para colocar el menor elemento en la cima (ESTO NO CAMBIA)
    
}


