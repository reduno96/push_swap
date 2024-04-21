/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <rel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 15:13:04 by rel-mora          #+#    #+#             */
/*   Updated: 2024/04/21 12:26:34 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	del(void *content)
{
	free(content);
}

void	ft_del_node(t_stack *stack_a)
{
	if (!stack_a)
		return ;
	free(stack_a);
}

void	ft_free_stack(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		ft_del_node(*stack);
		*stack = tmp;
	}
}

void	ft_error(t_stack *stack_a)
{
	ft_free_stack(&stack_a);
	stack_a = NULL;
	ft_putendl_fd("Error", 2);
	exit(1);
}
