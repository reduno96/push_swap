/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <rel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 15:12:35 by rel-mora          #+#    #+#             */
/*   Updated: 2024/05/17 15:11:44 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

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

void				ft_check_double(t_stack *stack_a);
int					ft_check_num(char *str);
int					ft_toi(const char *str, t_stack *stack_a);

void				ft_free_stack2(t_stack *stack);
void				ft_error(t_stack *stack);

void				ft_iter_node(t_stack *lst, void (*f)(int));
t_stack				*ft_last_node(t_stack *stack);
t_stack				*ft_new(int content);
void				ft_add(t_stack **stack, t_stack *new_node);
int					ft_stack_len(t_stack **stack_a);

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
void				ft_rra(t_stack **stack_a);
void				ft_rrb(t_stack **stack_b);
void				ft_rrr(t_stack **stack_a, t_stack **stack_b);

void				ft_sort(t_stack **stack_a, t_stack **stack_b);
void				ft_sort_2(t_stack **stack_a);
void				ft_sort_3(t_stack **stack_a);
void				ft_sort_4(t_stack **stack_a, t_stack **stack_b);
void				ft_sort_5(t_stack **stack_a, t_stack **stack_b);
void				ft_sort_range(t_stack **stack_a, t_stack **stack_b, int min,
						int max);
int					ft_stack_len(t_stack **stack_a);
int					ft_find_min(t_stack **stack_a);

void				ft_indexing(t_stack *stack_a);
int					find_index_by_value(t_stack *stack, int value);
void				ft_sort_final(t_stack **stack_a, t_stack **stack_b);
int					ft_is_sorted(t_stack *stack);

#endif