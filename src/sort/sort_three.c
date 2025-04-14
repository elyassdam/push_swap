  #include "./includes/ft_push_swap.h"

void sort_three(t_stack *a)
{
     t_list *first;
    t_list *last;

    if (!a || !a->top || !a->top->next)
        return;
    a->size = ft_lstsize(a->top);
    first = a->top;
    last = a->top;
    while (last->next != NULL)
        last = last->next;
    if (first->next > first->next->next && last < first->next)
        rra(a);
    if (first->next < first->next->next)
        sa(a);
    if ()
    
}