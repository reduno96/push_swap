/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <rel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 21:39:19 by rel-mora          #+#    #+#             */
/*   Updated: 2024/03/26 23:04:31 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_int(int n)
{
	printf("%d\n", n);
}

int	main(int argc, char **argv)
{
	// t_stack *stack_a;
	t_stack	*stack_a;

	stack_a = NULL;
	t_stack *stack_b;

	stack_b = NULL;
	if (argc > 1)
	{
		stack_a = add_nums_to_stack(argc, argv);
		// ft_swap(&stack_a);
		// ft_swap(&stack_b);
		// ft_push_a(&stack_b, &stack_a);
		ft_iter_node(stack_a, ft_print_int);
		printf("_____\n");
		// ft_push_b(&stack_a, &stack_b);

		 ft_rotate(&stack_a);

		ft_iter_node(stack_a, ft_print_int);

		// Print the content of stack_a
		ft_free_stack2(stack_a);
		// Free stack_a after you're done using it
	}
}