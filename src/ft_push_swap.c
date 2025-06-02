
#include "../includes/ft_push_swap.h" // Assuming this includes t_stack and t_list definitions
#include <limits.h> // For INT_MIN, INT_MAX
#include <stdio.h>  // For NULL, potentially for debugging (though ft_printf is used)
#include <stdlib.h> // For malloc, free, strtol
#include <unistd.h> // For write
#include <errno.h>  // For ERANGE

// --- Utility Functions (Provided or Improved) ---

/* void ft_error(void)
{
    write(2, "Error\n", 6);
}

// Checks for duplicate integer values in the stack
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
                return (1); // Duplicate found
            j = j->next;
        }
        i = i->next;
    }
    return (0); // No duplicates
}

// Adds an integer value to the back of the stack
void ft_lstadd_back_int(t_stack *stack, int value)
{
    // Allocate memory for the integer content
    int *new_int_content = malloc(sizeof(int));
    if (!new_int_content)
    {
        // Handle malloc failure (e.g., print error and exit or return)
        // For push_swap, usually a global error handling might be in place
        ft_error(); // Example: calling your error function
        exit(1); // Exit if memory allocation fails critically
    }
    *new_int_content = value; // Assign the value

    // Create a new list node with the allocated content
    t_list *new_node = ft_lstnew(new_int_content);
    if (!new_node)
    {
        // Handle ft_lstnew failure (e.g., free new_int_content and exit)
        free(new_int_content); // Free the content if node creation fails
        ft_error();
        exit(1);
    }

    ft_lstadd_back(&stack->top, new_node); // Add the node to the stack
    stack->size++; // Increment stack size
}

// Improved: Checks if a string represents a valid integer (including sign and ensuring digits exist)
int ft_isdigit_str(const char *str)
{
    int i;
    int has_digit; // Flag to ensure at least one digit is present

    if (!str || *str == '\0')
        return (0); // NULL or empty string is not a valid number

    i = 0;
    has_digit = 0; // Initialize flag

    // Handle optional sign (+ or -)
    if (str[i] == '-' || str[i] == '+')
    {
        i++;
    }

    // Iterate through the rest of the string, checking for digits
    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (0); // Found a non-digit character
        has_digit = 1; // Mark that at least one digit was found
        i++;
    }
    return (has_digit); // Return 1 if at least one digit was found, 0 otherwise
}

// Helper function to free the char** array returned by ft_split
void ft_free_split(char **split_array)
{
    int i;

    if (!split_array)
        return;
    i = 0;
    while (split_array[i])
    {
        free(split_array[i]); // Free each individual string
        i++;
    }
    free(split_array); // Free the array of pointers itself
}

// --- Main Function ---

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
    int     i;
    int     j;
    long    long_value;
    char    **split_args;
    char    *endptr;

    // Allocate memory for stack structures
    stack_a = malloc(sizeof(t_stack));
    stack_b = malloc(sizeof(t_stack));
    if (!stack_a || !stack_b)
    {
        ft_error();
        // If one allocation fails, ensure the other is freed if it succeeded
        if (stack_a) free(stack_a);
        if (stack_b) free(stack_b);
        return (1);
    }

    // Initialize stacks
    stack_a->top = NULL;
    stack_a->size = 0;
    stack_b->top = NULL;
    stack_b->size = 0;

    // Handle no arguments (only program name)
    if (argc < 2)
    {
        free(stack_a); // Free allocated stack structures
        free(stack_b);
        return (0); // Exit gracefully as per push_swap spec for no arguments
    }

    i = 1;
    while (i < argc)
    {
        // Split each argument string by spaces
        split_args = ft_split(argv[i], ' ');
        if (!split_args) // Handle ft_split allocation failure
        {
            ft_lstclear(&stack_a->top, free); // Clean up stack_a content
            ft_lstclear(&stack_b->top, free); // Clean up stack_b content (empty but good practice)
            ft_error();
            free(stack_a);
            free(stack_b);
            return (1);
        }

        j = 0;
        // Handle empty strings resulting from split (e.g., "   " or trailing spaces)
        if (!split_args[0])
        {
            ft_free_split(split_args);
            i++;
            continue; // Skip to next argv if split resulted in an empty array
        }

        while (split_args[j])
        {
            // 1. Validate if the string is a valid number format
            if (!ft_isdigit_str(split_args[j]))
            {
                ft_lstclear(&stack_a->top, free);
                ft_lstclear(&stack_b->top, free);
                ft_free_split(split_args); // Free split_args before exiting
                ft_error();
                free(stack_a);
                free(stack_b);
                return (1);
            }

            // 2. Safely convert string to long and check for overflow/underflow
            errno = 0; // Clear errno before strtol call for reliable error checking
            long_value = strtol(split_args[j], &endptr, 10);

            // Check for conversion errors (ERANGE for overflow/underflow)
            if (errno == ERANGE || long_value > INT_MAX || long_value < INT_MIN)
            {
                ft_lstclear(&stack_a->top, free);
                ft_lstclear(&stack_b->top, free);
                ft_free_split(split_args);
                ft_error();
                free(stack_a);
                free(stack_b);
                return (1);
            }

            // Check if the entire string was consumed by strtol (no trailing non-numeric characters)
            if (*endptr != '\0')
            {
                ft_lstclear(&stack_a->top, free);
                ft_lstclear(&stack_b->top, free);
                ft_free_split(split_args);
                ft_error();
                free(stack_a);
                free(stack_b);
                return (1);
            }

            // 3. Add the valid integer to stack_a
            ft_lstadd_back_int(stack_a, (int)long_value);
            j++;
        }
        ft_free_split(split_args); // Free split_args after processing each argv[i]
        i++;
    }

    // Check for duplicates after all arguments are parsed into stack_a
    if (ft_check_duplicates(stack_a)) // ft_check_duplicates already handles stack_a->top == NULL
    {
        ft_lstclear(&stack_a->top, free);
        ft_lstclear(&stack_b->top, free);
        ft_error();
        free(stack_a);
        free(stack_b);
        return (1);
    }

    // --- Debugging: Initial Stack State ---
    ft_printf("--- Initial State ---\n");
    ft_print_stack(stack_a);
    ft_print_stack(stack_b);
    ft_printf("Stack 'a' size: %d\n", stack_a->size);
    ft_printf("-----------------------\n\n");

    // --- Sorting Logic based on stack size ---
    if (is_sorted(stack_a)) // Check if already sorted
    {
        ft_printf("Stack 'a' is already sorted! 🎉\n");
    }
    else if (stack_a->size == 2)
    {
        // For 2 elements, if not sorted, only 'sa' is needed
        // Assuming your `sa` function is defined and handles the print.
        // If not, you'd call it here: sa(stack_a);
        if (*(int*)stack_a->top->content > *(int*)stack_a->top->next->content)
            sa(stack_a); // Call your actual sa function
    }
    else if (stack_a->size == 3)
    {
        sort_three(stack_a);
    }
    else if (stack_a->size == 5)
    {
        sort_five(stack_a, stack_b);
    }
    else if (stack_a->size > 3) // Covers 4, and N > 5. (Sizes 2, 3, 5 are handled specifically)
    {
        sort(stack_a, stack_b); // Call your general sorting algorithm
    }

    // --- Debugging: Final Stack State and Sorted Check ---
    ft_printf("\n--- Final State ---\n");
    ft_print_stack(stack_a);
    ft_print_stack(stack_b);
    ft_printf("Stack 'a' size: %d\n", stack_a->size);
    ft_printf("---------------------\n");

    if (is_sorted(stack_a))
        ft_printf("Stack 'a' is sorted! 🎉\n");
    else
        ft_printf("Stack 'a' is NOT sorted. 😔\n");

    // --- Memory Deallocation ---
    ft_lstclear(&stack_a->top, free); // Free all nodes and their content in stack_a
    ft_lstclear(&stack_b->top, free); // Free all nodes and their content in stack_b (should be empty if sorted correctly)
    free(stack_a); // Free the stack structure itself
    free(stack_b); // Free the stack structure itself

    return (0); // Indicate successful execution

    if (is_sorted(stack_a)) // Check if already sorted
{
    ft_printf("Stack 'a' is already sorted! 🎉\n");
}
else if (stack_a->size == 5)
    sort_five(stack_a, stack_b);
else if (stack_a->size == 3)
    sort_three(stack_a);
else if (stack_a->size > 1) 
{
    sort(stack_a, stack_b);
    final_rotate(stack_a); 
}

    ft_lstclear(&stack_a->top, free); 
    ft_lstclear(&stack_b->top, free); 
    free(stack_a); 
    free(stack_b); 
    return (0);
} */
/* ************************************************************************** */
/* */
/* :::      ::::::::   */
/* push_swap.c                                        :+:      :+:    :+:   */
/* +:+ +:+         +:+     */
/* By: yael-you <yael-you@student.42.fr>          +#+  +:+       +#+        */
/* +#+#+#+#+#+   +#+           */
/* Created: 2025/05/11 07:59:54 by yael-you          #+#    #+#             */
/* Updated: 2025/05/28 15:49:12 by yael-you         ###   ########.fr       */
/* */
/* ************************************************************************** */

#include "../includes/ft_push_swap.h"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

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
    int *new_int_content = malloc(sizeof(int));
    if (!new_int_content)
    {
        ft_error();
        exit(1);
    }
    *new_int_content = value;

    t_list *new_node = ft_lstnew(new_int_content);
    if (!new_node)
    {
        free(new_int_content);
        ft_error();
        exit(1);
    }

    ft_lstadd_back(&stack->top, new_node);
    stack->size++;
}

int ft_isdigit_str(const char *str)
{
    int i;
    int has_digit;

    if (!str || *str == '\0')
        return (0);

    i = 0;
    has_digit = 0;

    if (str[i] == '-' || str[i] == '+')
    {
        i++;
    }

    while (str[i])
    {
        if (!ft_isdigit(str[i]))
            return (0);
        has_digit = 1;
        i++;
    }
    return (has_digit);
}

void ft_free_split(char **split_array)
{
    int i;

    if (!split_array)
        return;
    i = 0;
    while (split_array[i])
    {
        free(split_array[i]);
        i++;
    }
    free(split_array);
}

int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
    int     i;
    int     j;
    long    long_value;
    char    **split_args;
    char    *endptr;

    stack_a = malloc(sizeof(t_stack));
    stack_b = malloc(sizeof(t_stack));
    if (!stack_a || !stack_b)
    {
        ft_error();
        if (stack_a) free(stack_a);
        if (stack_b) free(stack_b);
        return (1);
    }

    stack_a->top = NULL;
    stack_a->size = 0;
    stack_b->top = NULL;
    stack_b->size = 0;

    if (argc < 2)
    {
        free(stack_a);
        free(stack_b);
        return (0);
    }

    i = 1;
    while (i < argc)
    {
        split_args = ft_split(argv[i], ' ');
        if (!split_args)
        {
            ft_lstclear(&stack_a->top, free);
            ft_lstclear(&stack_b->top, free);
            ft_error();
            free(stack_a);
            free(stack_b);
            return (1);
        }

        j = 0;
        if (!split_args[0])
        {
            ft_free_split(split_args);
            i++;
            continue;
        }

        while (split_args[j])
        {
            if (!ft_isdigit_str(split_args[j]))
            {
                ft_lstclear(&stack_a->top, free);
                ft_lstclear(&stack_b->top, free);
                ft_free_split(split_args);
                ft_error();
                free(stack_a);
                free(stack_b);
                return (1);
            }

            errno = 0;
            long_value = strtol(split_args[j], &endptr, 10);

            if (errno == ERANGE || long_value > INT_MAX || long_value < INT_MIN)
            {
                ft_lstclear(&stack_a->top, free);
                ft_lstclear(&stack_b->top, free);
                ft_free_split(split_args);
                ft_error();
                free(stack_a);
                free(stack_b);
                return (1);
            }

            if (*endptr != '\0')
            {
                ft_lstclear(&stack_a->top, free);
                ft_lstclear(&stack_b->top, free);
                ft_free_split(split_args);
                ft_error();
                free(stack_a);
                free(stack_b);
                return (1);
            }

            ft_lstadd_back_int(stack_a, (int)long_value);
            j++;
        }
        ft_free_split(split_args);
        i++;
    }

    if (ft_check_duplicates(stack_a))
    {
        ft_lstclear(&stack_a->top, free);
        ft_lstclear(&stack_b->top, free);
        ft_error();
        free(stack_a);
        free(stack_b);
        return (1);
    }

    // --- Debugging: Initial Stack State (comentado) ---
    // ft_printf("--- Initial State ---\n");
    // ft_print_stack(stack_a);
    // ft_print_stack(stack_b);
    // ft_printf("Stack 'a' size: %d\n", stack_a->size);
    // ft_printf("-----------------------\n\n");

    // --- Sorting Logic ---
    if (is_sorted(stack_a))
    {
        // ft_printf("Stack 'a' is already sorted! 🎉\n"); // Comentado
    }
    else if (stack_a->size > 1)
    {
        sort(stack_a, stack_b);
    }

    // --- Debugging: Final Stack State and Sorted Check (comentado) ---
    // ft_printf("\n--- Final State ---\n");
    // ft_print_stack(stack_a);
    // ft_print_stack(stack_b);
    // ft_printf("Stack 'a' size: %d\n", stack_a->size);
    // ft_printf("---------------------\n");

    // if (is_sorted(stack_a))
    //     ft_printf("Stack 'a' is sorted! 🎉\n");
    // else
    //     ft_printf("Stack 'a' is NOT sorted. 😔\n");

    // --- Memory Deallocation ---
    ft_lstclear(&stack_a->top, free);
    ft_lstclear(&stack_b->top, free);
    free(stack_a);
    free(stack_b);

    return (0);
}
