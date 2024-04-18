/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <rel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 21:39:19 by rel-mora          #+#    #+#             */
/*   Updated: 2024/04/18 18:48:41 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		add_nums_to_stack(&stack_a, argc, argv);
		if (ft_is_sorted(stack_a) == 0)
			ft_sort(&stack_a, &stack_b);
		ft_free_stack2(stack_a);
		ft_free_stack2(stack_b);
	}
}
