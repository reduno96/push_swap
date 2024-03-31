/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_rules.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <reduno96@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 13:28:21 by rel-mora          #+#    #+#             */
/*   Updated: 2024/03/31 13:56:55 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **stack_a)
{
	t_stack	*fst;
	t_stack	*scd;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	fst = *stack_a;
	scd = (*stack_a)->next;
	if (scd->next != NULL)
		scd->next->prev = fst;
	fst->next = scd->next;
	scd->next = fst;
	fst->prev = scd;
	scd->prev = NULL;
	*stack_a = scd;
}

void	ft_sa(t_stack **stack_a)
{
	ft_swap(stack_a);
	write(1, "sa", 2);
}

void	ft_sb(t_stack **stack_b)
{
	ft_swap(stack_b);
	write(1, "sb", 2);
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap(stack_a);
	ft_swap(stack_b);
	write(1, "ss", 2);
}
