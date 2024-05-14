/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <rel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:15:53 by rel-mora          #+#    #+#             */
/*   Updated: 2024/05/14 12:17:44 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp->next != NULL)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_middle(t_stack *stack, int middle, int max_index)
{
	t_stack	*cpy;

	cpy = stack;
	while (--middle && cpy->index != max_index)
		cpy = cpy->next;
	if (middle)
		return (1);
	return (0);
}

void	ft_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	len;

	len = ft_stack_len(stack_a);
	if (len == 2)
		ft_sort_2(stack_a);
	else if (len == 3)
		ft_sort_3(stack_a);
	else if (len == 4)
		ft_sort_4(stack_a, stack_b);
	else if (len == 5)
		ft_sort_5(stack_a, stack_b);
	else if (len > 5 && len <= 100)
		ft_sort_range(stack_a, stack_b, 0, 15);
	else if (len > 100)
		ft_sort_range(stack_a, stack_b, 0, 35);
}

void	ft_sort_range(t_stack **stack_a, t_stack **stack_b, int min, int max)
{
	ft_indexing(*stack_a);
	while ((*stack_a) != NULL)
	{
		if ((*stack_a)->index >= min && (*stack_a)->index <= max)
		{
			ft_pb(stack_b, stack_a);
			min++;
			max++;
		}
		else if ((*stack_a)->index < min)
		{
			ft_pb(stack_b, stack_a);
			ft_rb(stack_b);
			min++;
			max++;
		}
		else
			ft_ra(stack_a);
	}
	ft_sort_final(stack_a, stack_b);
}

void	ft_sort_final(t_stack **stack_a, t_stack **stack_b)
{
	while (*stack_b != NULL)
	{
		if (ft_middle(*stack_b, ft_stack_len(stack_b) / 2, ft_stack_len(stack_b)
				- 1))
			while ((*stack_b)->index != ft_stack_len(stack_b) - 1)
				ft_rb(stack_b);
		else
			while ((*stack_b)->index != ft_stack_len(stack_b) - 1)
				ft_rrb(stack_b);
		ft_pa(stack_a, stack_b);
	}
}
