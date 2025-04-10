
#include <unistd.h>
#include <stdlib.h>
#include <stdlib.h>
# include "../libft/libft.h"  // Para ft_atoi, ft_split, etc.
# define FT_PUSH_SWAP_H

//structures
typedef struct s_node
{
    int value;
   struct s_node *next;
} t_node;
typedef struct s_stack
{
    t_list *top; 
    int size;
} t_stack;


void	swap(t_stack *swaped_stack);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void    ra (t_stack *a);
void    rb (t_stack *b);
void    rr (t_stack *a, t_stack *b);
void    rra (t_stack *a);
int	parse_args(t_stack *stack, int argc, char **argv);
int	ft_check_duplicates(t_stack *stack);

