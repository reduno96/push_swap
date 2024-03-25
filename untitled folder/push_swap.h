#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>


typedef struct s_stack
{
	int	content;
	struct s_stack *next;
} t_stack;


void	add_nums_to_stack(t_stack *stack, int argc, char **argv);
void	ft_error(t_stack *stack);
#endif