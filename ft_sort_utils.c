/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <reduno96@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 13:37:54 by rel-mora          #+#    #+#             */
/*   Updated: 2024/04/01 03:36:23 by rel-mora         ###   ########.fr       */
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

void	ft_sort_range(t_stack **stack_a, t_stack **stack_b)
{
	int		len;
	t_var	idx;
	t_stack	*tmp;
	int		*array;

	len = ft_stack_len(stack_a);
	array = malloc(len * sizeof(int));
	tmp = *stack_a;
	while (idx.i < len)
	{
		array[idx.i++] = tmp->content;
		tmp = tmp->next;
	}
	ft_babel_sort(array, len);
	tmp = *stack_a;
	while (tmp != NULL)
	{
		tmp->index = ft_find_index(array, len, tmp->content);
		tmp = tmp->next;
	}
	ft_indexing(stack_a, stack_b);
	free(array);
}
