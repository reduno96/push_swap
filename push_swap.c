/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <reduno96@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 21:39:19 by rel-mora          #+#    #+#             */
/*   Updated: 2024/04/01 03:31:53 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_int(int n)
{
	printf("%d\n", n);
}

int	main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		add_nums_to_stack(&stack_a, argc, argv);
		ft_sort(&stack_a, &stack_b);
		ft_free_stack2(stack_a);
		ft_free_stack2(stack_b);
	}
}