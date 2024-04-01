/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <reduno96@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:15:53 by rel-mora          #+#    #+#             */
/*   Updated: 2024/04/01 02:02:09 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_min(t_stack **stack_a)
{
	t_stack	*tmp;
	int		min;

	tmp = *stack_a;
	min = tmp->content;
	while (tmp != NULL)
	{
		if (tmp->content < min)
			min = tmp->content;
		tmp = tmp->next;
	}
	return (min);
}

int	ft_find_max(t_stack **stack_a)
{
	t_stack	*tmp;
	int		max;

	tmp = *stack_a;
	max = tmp->content;
	while (tmp != NULL)
	{
		if (tmp->content > max)
			max = tmp->content;
		tmp = tmp->next;
	}
	return (max);
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
	else if (len > 5 && len < 100)
		ft_sort_range(stack_a, stack_b);
	else if (len >= 100)
		ft_sort_range(stack_a, stack_b);
}
