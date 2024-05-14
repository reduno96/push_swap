/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_rules_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <rel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 13:28:21 by rel-mora          #+#    #+#             */
/*   Updated: 2024/05/14 12:15:51 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_swap(t_stack **stack_a)
{
	t_stack	*first;
	t_stack	*second;

	first = *stack_a;
	second = (*stack_a)->next;
	first->next = second->next;
	second->next = first;
	first->prev = second;
	second->prev = NULL;
	*stack_a = second;
}

void	ft_sa(t_stack **stack_a)
{
	ft_swap(stack_a);
	write(1, "sa\n", 3);
}

void	ft_sb(t_stack **stack_b)
{
	ft_swap(stack_b);
	write(1, "sb\n", 3);
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	write(1, "ss\n", 3);
}
