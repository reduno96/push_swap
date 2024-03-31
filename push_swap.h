#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>

/*
delete
 */

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

typedef struct s_var
{
	int				i;
	int				j;
}					t_var;

typedef struct s_stack
{
	int				content;
	int				index;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

void				add_nums_to_stack(t_stack **stack_a, int argc, char **argv);
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
void				ft_sa(t_stack **stack_a);
void				ft_sb(t_stack **stack_b);
void				ft_ss(t_stack **stack_a, t_stack **stack_b);

void				ft_push(t_stack **stack_a, t_stack **stack_b);
void				ft_pa(t_stack **stack_a, t_stack **stack_b);
void				ft_pb(t_stack **stack_b, t_stack **stack_a);

void				ft_rotate(t_stack **stack);
void				ft_ra(t_stack **stack_a);
void				ft_rb(t_stack **stack_b);
void				ft_rr(t_stack **stack_a, t_stack **stack_b);

void				ft_reverse_rotate(t_stack **stack_a);
void				rra(t_stack **stack_a);
void				rrb(t_stack **stack_b);
void				rrr(t_stack **stack_a, t_stack **stack_b);

#endif