
#include <unistd.h>
#include <stdlib.h>
#include <stdlib.h>

void	swap(t_stack *swaped_stack);
void	ss(t_stack *a, t_stack *b);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *a, t_stack *b);
void    ra (t_stack *a);
void    rb (t_stack *b);
void    rr (t_stack *a, t_stack *b);
void    rra (t_stack *a);


//structures
typedef struct s_stack
{
    int size;
    t_node *top;
} t_stack;

typedef struct s_node
{
    int value;
    struct s_node *next;
} t_node;
