#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

int					main(int argc, char **argv);
void				add_nums_to_stack(int argc, char **argv);
void				ft_error(t_stack *stack);
#endif