/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate_rules.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <reduno96@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 13:38:26 by rel-mora          #+#    #+#             */
/*   Updated: 2024/03/31 13:57:58 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (!(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	last = ft_last_node(*stack);
	*stack = first->next;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	(*stack)->prev = NULL;
}

void	ft_ra(t_stack **stack_a)
{
	ft_rotate(stack_a);
	write(1, "ra", 2);
}

void	ft_rb(t_stack **stack_b)
{
	ft_rotate(stack_b);
	write(1, "rb", 2);
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate(stack_a);
	ft_rotate(stack_b);
	write(1, "rr", 2);
}
