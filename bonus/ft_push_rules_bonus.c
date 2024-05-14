/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_rules_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <reduno96@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 13:32:42 by rel-mora          #+#    #+#             */
/*   Updated: 2024/05/13 15:18:38 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_push(t_stack **src, t_stack **dst)
{
	t_stack	*first;

	first = *dst;
	*dst = first->next;
	first->prev = NULL;
	first->next = *src;
	*src = first;
}

void	ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	ft_push(stack_a, stack_b);
	write(1, "pa\n", 3);
}

void	ft_pb(t_stack **stack_b, t_stack **stack_a)
{
	ft_push(stack_b, stack_a);
	write(1, "pb\n", 3);
}
int