/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <rel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 15:13:04 by rel-mora          #+#    #+#             */
/*   Updated: 2024/05/14 12:15:09 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_check_stored(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_is_sorted(*stack_a) == 1 && *stack_b == NULL)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	exit(0);
}

void	ft_free_stack2(t_stack *stack)
{
	t_stack	*tmp;

	while (stack != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

void	ft_error(t_stack *stack_a)
{
	ft_free_stack2(stack_a);
	stack_a = NULL;
	ft_putendl_fd("Error", 2);
	exit(1);
}
