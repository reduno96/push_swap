/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <rel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 15:13:04 by rel-mora          #+#    #+#             */
/*   Updated: 2024/05/14 12:17:13 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
