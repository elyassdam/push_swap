  #include "../includes/ft_push_swap.h"

void sort_three(t_stack *a)
{
    int *first;
    int *second;
    int *last;

    if (!a || !a->top || !a->top->next)
        return;
    first = a->top->content;
    second = a->top->next->content;
    last = a->top->next->next->content;
    
    if (first > second && second < last && first < last)
        sa(a);
    else if (first > second && second < last)
    {    sa(a);
        rra(a);
    }
    else if(first < second && second > last && first < last)
    {
        sa(a);
        ra(a);
    }
    else if (first > second && second < last &&  first < last)
       ra(a);
    else if (first < second && second > last && first < last)
        rra (a);    
}
