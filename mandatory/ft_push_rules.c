/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_rules.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <rel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 13:32:42 by rel-mora          #+#    #+#             */
/*   Updated: 2024/05/17 15:14:35 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_stack **src, t_stack **dst)
{
	t_stack	*first;

	if (*dst == NULL)
		return ;
	first = *dst;
	*dst = (*dst)->next;
	if (*dst != NULL)
		(*dst)->prev = NULL;
	first->prev = NULL;
	first->next = *src;
	if (*src != NULL)
		(*src)->prev = first;
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
