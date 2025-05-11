// ft_push_swap.h
#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include "../libft/libft.h" // Para ft_atoi, ft_split, etc.
# include <stdlib.h>
# include <unistd.h>

// Structures
typedef struct s_node
{
	int				value;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_list			*top;
	int				size;
	char			stack_id;
}					t_stack;

// Function prototypes
void				sa(t_stack *a);
void				sb(t_stack *b);
void				ss(t_stack *a, t_stack *b);
void				pa(t_stack *a, t_stack *b);
void				pb(t_stack *a, t_stack *b);
void				ra(t_stack *a);
void				rb(t_stack *b);
void				rr(t_stack *a, t_stack *b);
void				rra(t_stack *a);
void				rrb(t_stack *b);
void				rrr(t_stack *a, t_stack *b);
int					parse_args(t_stack *stack, int argc, char **argv);
int					ft_check_duplicates(t_stack *stack);
void	ft_error(void);                                 
		// Si tienes una función ft_error
void	ft_lstadd_back_int(t_stack *stack, int value);   // Si la usas aquí
void	ft_print_stack(t_stack *stack, char stack_name); // Si la usas aquí
void				sort_three(t_stack *a);
void				sort_five(t_stack *a, t_stack *b);
// aux
int					get_max(t_stack *a);
int					get_min(t_stack *a);
int					get_pos(t_stack *a, int value);
int					cost(t_stack *a, t_stack *b, int value);
int					cheapest(t_stack *a, t_stack *b);
int					find_couple(t_stack *b, int value_a);
int					get_moves_to_top(t_stack *stack, int value);
int					do_move_top(t_stack *a, t_stack *b);
#endif