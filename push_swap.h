#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>

/*
delete
 */

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

t_stack				*add_nums_to_stack(int argc, char **argv);
int					ft_check_duplicate(t_stack *stack_a);
int					ft_check_num(char *str);
void				ft_free_stack2(t_stack *stack);
void				ft_free_split(char **str);

void				ft_error(t_stack *stack);
void				ft_iter_node(t_stack *lst, void (*f)(int));
t_stack				*ft_last_node(t_stack *stack);
t_stack				*ft_new(int content);
void				ft_add(t_stack **stack, t_stack *new_node);
int					ft_toi(const char *str, t_stack *stack_a);

void				ft_swap(t_stack **stack_a);
void				ft_rotate(t_stack **stack);
void				ft_reverse_rotate(t_stack **stack_a);
void				ft_swap_a_b(t_stack *stack_a, t_stack *stack_b);
void				ft_push_a(t_stack **stack_a, t_stack **stack_b);
void				ft_push(t_stack **stack_a, t_stack **stack_b);
#endif