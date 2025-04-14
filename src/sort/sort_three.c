  #include "./includes/ft_push_swap.h"

void sort_three(t_stack *a)
{
    int first;
    int second;
    int last;

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
    else if (first < second && second > last && first < first)
        rra (a);    
}
void sort_five(t_stack *a, t_stack *b)
{
    int max;
    t_list *i;

    i = a->top;
    max = i->content;
    while (i->next != NULL)
    {    i = i->next;
        if (max < i->content)
            max = i->content;
        i = i->next;
    }
    if (a->top->content = max)
    while (a->top->content == max)
     if (a->top->content = max)
        rra(a);
    
    pb (a,b);
    
}