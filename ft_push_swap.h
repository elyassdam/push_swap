




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
