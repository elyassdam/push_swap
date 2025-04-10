/* push_swap.c */

#include "../includes/ft_push_swap.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

      void ft_error(void)
{
    write(2, "Error\n", 6);
}
int ft_check_duplicates(t_stack *stack)
{
    t_list *i;
    t_list *j;
    int *val_i;
    int *val_j;

    i = stack->top;
    while (i)
    {
        val_i = (int *)i->content;
        j = i->next;
        while (j)
        {
            val_j = (int *)j->content;
            if (*val_i == *val_j)
                return (1);
            j = j->next;
        }
        i = i->next;
    }
    return (0);
}

void ft_lstadd_back_int(t_stack *stack, int value)
{
    t_list *new_node = ft_lstnew(malloc(sizeof(int)));
    if (new_node)
    {
        *(int *)new_node->content = value;
        ft_lstadd_back(&stack->top, new_node);
        stack->size++;
    }
}
int ft_isdigit_str(const char *str)
{
    if (!str || *str == '\0')
        return (0);
    int i = 0;
    while (str[i])
    {
        if (!ft_isdigit(str[i]) && (i == 0 && str[i] == '-'))
        {
            i++;
            continue;
        }
        if (!ft_isdigit(str[i]))
            return (0);
        i++;
    }
    return (1);
}
int parse_args(t_stack *stack, int argc, char **argv)
{
    int i;
    int value;

    i = 1;
    while (i < argc)
    {
        if (!ft_isdigit_str(argv[i])) 
            return (0);
        value = ft_atoi(argv[i]);
        if (value < INT_MIN || value > INT_MAX)
            return (0);
        ft_lstadd_back_int(stack, value);
        i++;
    }
    if (stack->top && ft_check_duplicates(stack))
        return (0);
    return (1);
}

int main(int argc, char **argv)
{
    t_stack *stack;
    int     i;
    int     value;

    stack = malloc(sizeof(t_stack));
    if (!stack)
        return (1);
    stack->top = NULL;
    stack->size = 0;

    if (argc < 2)
        return (0);

    i = 1;
    while (i < argc)
    {
        char **split_args = ft_split(argv[i], ' ');
        int j = 0;
        while (split_args[j])
        {
            if (!ft_isdigit_str(split_args[j]))
            {
                ft_lstclear(&stack->top, free);
                ft_error();
                return (1);
            }
            value = ft_atoi(split_args[j]);
            ft_lstadd_back_int(stack, value);
            free(split_args[j]);
            j++;
        }
        free(split_args);
        i++;
    }

    if (stack->top && ft_check_duplicates(stack))
    {
        ft_lstclear(&stack->top, free);
        ft_error();
        free(stack);
        return (1);
    }
   }

