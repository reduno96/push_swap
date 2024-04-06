/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <reduno96@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/31 15:13:04 by rel-mora          #+#    #+#             */
/*   Updated: 2024/04/06 01:49:09 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_stored(t_stack **stack_a, t_stack **stack_b, char **read_line)
{
	if (ft_is_sorted(*stack_a) == 1 && *stack_b == NULL)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	exit(0);
}

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
	exit(0);
}
