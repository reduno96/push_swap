/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_rules_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <rel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 13:32:42 by rel-mora          #+#    #+#             */
/*   Updated: 2024/05/15 19:40:01 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_push(t_stack **src, t_stack **dst)
{
	t_stack	*fst_b;

	if (*dst == NULL)
		return ;
	fst_b = *dst;
	*dst = (*dst)->next;
	if (*dst != NULL)
		(*dst)->prev = NULL;
	fst_b->prev = NULL;
	fst_b->next = *src;
	if (*src != NULL)
		(*src)->prev = fst_b;
	*src = fst_b;
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
