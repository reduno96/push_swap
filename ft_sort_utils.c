/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <reduno96@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:37:54 by rel-mora          #+#    #+#             */
/*   Updated: 2024/04/02 04:00:36 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_2(t_stack **stack_a)
{
	if ((*stack_a)->content > (*stack_a)->next->content)
		ft_sa(stack_a);
}

void	ft_sort_3(t_stack **stack_a)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->content;
	b = (*stack_a)->next->content;
	c = (*stack_a)->next->next->content;
	if (!((*stack_a)->content) || !((*stack_a)->next->content)
		|| !((*stack_a)->next->next->content))
		return ;
	if (a > b && b < c && a < c)
		ft_sa(stack_a);
	else if (a > b && b > c && a > c)
	{
		ft_sa(stack_a);
		ft_rra(stack_a);
	}
	else if (a > b && b < c && a > c)
		ft_ra(stack_a);
	else if (a < b && b > c && a > c)
	{
		ft_sa(stack_a);
		ft_ra(stack_a);
	}
	else if (a < b && b > c && a < c)
		ft_rra(stack_a);
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
			ft_pb(stack_b, stack_a);
			break ;
		}
		ft_ra(stack_a);
		i++;
	}
	ft_sort_3(stack_a);
	ft_pa(stack_a, stack_b);
}

void	ft_sort_5(t_stack **stack_a, t_stack **stack_b)
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
			ft_pb(stack_b, stack_a);
			break ;
		}
		ft_ra(stack_a);
		i++;
	}
	ft_sort_4(stack_a, stack_b);
	ft_pa(stack_a, stack_b);
}

void	ft_sort_range(t_stack **stack_a, t_stack **stack_b, int min, int max)
{
	int	len;

	// t_var	idx;
	(void)min;
	(void)max;
	len = ft_stack_len(stack_a);
	// idx.i = 0;
	// ft_indexing(*stack_a);
	// // while (idx.i < len)
	// // {
	// // 	if ((*stack_a)->index >= min && (*stack_a)->index <= max)
	// // 	{
	// // 		ft_pb(stack_b, stack_a);
	// // 		idx.i++;
	// // 	}
	// // 	else if ((*stack_a)->index < min)
	// // 	{
	// // 		ft_pb(stack_b, stack_a);
	// // 		ft_rb(stack_b);
	// // 		idx.i++;
	// // 	}
	// // 	else
	// // 		ft_ra(stack_a);
	// // 	min++;
	// // 	max++;
	// // }
	while (len--)
		ft_pb(stack_b, stack_a);
	ft_sort_final(stack_a, stack_b);
}
