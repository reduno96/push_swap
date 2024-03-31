/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate_rules.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <reduno96@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 13:45:51 by rel-mora          #+#    #+#             */
/*   Updated: 2024/03/31 13:59:12 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_reverse_rotate(t_stack **stack_a)
{
	t_stack	*last;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	last = ft_last_node(*stack_a);
	last->prev->next = NULL;
	last->next = *stack_a;
	(*stack_a)->prev = last;
	last->prev = NULL;
	*stack_a = last;
}

void	rra(t_stack **stack_a)
{
	ft_reverse_rotate(stack_a);
	write(1, "rra", 3);
}

void	rrb(t_stack **stack_b)
{
	ft_reverse_rotate(stack_b);
	write(1, "rrb", 3);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
	write(1, "rrr", 3);
}
