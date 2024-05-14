/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <reduno96@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:37:54 by rel-mora          #+#    #+#             */
/*   Updated: 2024/05/13 15:11:48 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

void	ft_sort_2(t_stack **stack_a)
{
	if ((*stack_a)->content > (*stack_a)->next->content)
		ft_swap(stack_a);
}

void	ft_sort_3(t_stack **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->content;
	b = (*stack_a)->next->content;
	c = (*stack_a)->next->next->content;
	if (a > b && a < c)
		ft_swap(stack_a);
	else if (a > b && a > c && b > c)
	{
		ft_swap(stack_a);
		ft_reverse_rotate(stack_a);
	}
	else if (a > b && a > c && b < c)
		ft_rotate(stack_a);
	else if (a < b && a > c)
		ft_reverse_rotate(stack_a);
	else if (a < b && a < c && b > c)
	{
		ft_swap(stack_a);
		ft_rotate(stack_a);
	}
}

void	ft_sort_4(t_stack **stack_a, t_stack **stack_b)
{
	int	len;
	int	i;
	int	min;

	len = ft_stack_len(stack_a);
	i = 0;
	min = ft_find_min(stack_a);
	while (i < len)
	{
		if ((*stack_a)->content == min)
		{
			ft_push(stack_b, stack_a);
			break ;
		}
		if ((*stack_a)->next != NULL)
			ft_reverse_rotate(stack_a);
		else
			ft_rotate(stack_a);
		i++;
	}
	ft_sort_3(stack_a);
	ft_push(stack_a, stack_b);
}

void	ft_sort_5(t_stack **stack_a, t_stack **stack_b)
{
	int	len;
	int	min;
	int	min_pos;

	len = ft_stack_len(stack_a);
	min = ft_find_min(stack_a);
	ft_indexing(*stack_a);
	min_pos = find_index_by_value(*stack_a, min);
	if (min_pos > len / 2)
	{
		while ((*stack_a)->content != min)
			ft_reverse_rotate(stack_a);
	}
	else
	{
		while ((*stack_a)->content != min)
			ft_rotate(stack_a);
	}
	ft_push(stack_b, stack_a);
	ft_sort_4(stack_a, stack_b);
	ft_push(stack_a, stack_b);
}
