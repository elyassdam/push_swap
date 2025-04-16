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
