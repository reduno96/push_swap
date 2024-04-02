/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <rel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 17:15:53 by rel-mora          #+#    #+#             */
/*   Updated: 2024/04/02 22:52:20 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_min_idx(t_stack **stack_a)
{
	t_stack	*tmp;
	int		min;

	tmp = *stack_a;
	min = tmp->index;
	while (tmp != NULL)
	{
		if (tmp->index < min)
			min = tmp->index;
		tmp = tmp->next;
	}
	return (min);
}
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
int ft_max_idx(t_stack **stack_a)
{
	t_stack	*tmp;
	int		max;

	tmp = *stack_a;
	max = tmp->index;
	while (tmp != NULL)
	{
		if (tmp->index > max)
			max = tmp->index;
		tmp = tmp->next;
	}
	return (max);
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
void	ft_print_int(int n)
{
	printf("%d ", n);
}


// void	ft_sort_final(t_stack **stack_a, t_stack **stack_b)
// {
// 	int	len;
// 	int	middle;
// 	int	i;

// 	i = 0;
// 	len = ft_stack_len(stack_b);
// 	middle = len / 2;
// 	while (*stack_b != NULL)
// 	{
// 		if ((*stack_b)->index <= middle)
// 		{
// 			while ((*stack_b)->index != ft_min_idx(stack_b))
// 				ft_rb(stack_b);
// 		}
// 		else
// 		{
// 			while ((*stack_b)->index !=  ft_min_idx(stack_b))
// 				ft_rrb(stack_b);
// 		}
// 		ft_pa(stack_a, stack_b);
// 	}
// }

int high_middle(t_stack *stack, int middle, int max_index)
{
	t_stack *cpy;

	cpy = stack;
	while (--middle && cpy->index != max_index)
		cpy = cpy->next;
	if (middle)
		return (1);
	return (0);
}

void	ft_sort_final(t_stack **stack_a, t_stack **stack_b)
{
	while (*stack_b != NULL)
	{
		if (high_middle(*stack_b, ft_stack_len(stack_b) / 2, ft_stack_len(stack_b) - 1))
		{
			while ((*stack_b)->index != ft_stack_len(stack_b) - 1)
				ft_rb(stack_b);
		}
		else
		{
			while ((*stack_b)->index != ft_stack_len(stack_b) - 1)
				ft_rrb(stack_b);
		}
		ft_pa(stack_a, stack_b);
	}
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
	else if (len >  5 && len <= 100)
		ft_sort_range(stack_a, stack_b, 0, 15);
	else if (len > 100)
		ft_sort_range(stack_a, stack_b, 0, 35);
}
