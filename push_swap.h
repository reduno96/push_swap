#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>

typedef struct s_node
{
	int				*content;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	t_node			content;
	int				*top;
	int				size;
}					t_stack;

int					main(int argc, char **argv);
void				add_nums_to_stack(t_stack *stack, int argc, char **argv);
void				ft_error(t_stack *stack);
#endif