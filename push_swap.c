/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <reduno96@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 21:39:19 by rel-mora          #+#    #+#             */
/*   Updated: 2024/03/27 12:05:01 by rel-mora         ###   ########.fr       */
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
	t_stack *stack_a;

	stack_a = NULL;
	t_stack *stack_b;

	stack_b = NULL;
	if (argc > 1)
	{
		stack_a = add_nums_to_stack(argc, argv);
		printf("swap_________________________\n");
		ft_swap(&stack_a);
		ft_iter_node(stack_a, ft_print_int);
		
		printf("swap_________________________\n");
		ft_swap(&stack_a);
		ft_iter_node(stack_a, ft_print_int);
		
		printf("push_to_b_________________________\n");
		ft_push(&stack_b, &stack_a);
		ft_push(&stack_b, &stack_a);
		ft_iter_node(stack_a, ft_print_int);

		printf("rotate_________________________\n");
		ft_rotate(&stack_a);
		ft_iter_node(stack_a, ft_print_int);

		// ft_reverse_rotate(&stack_a);
		// // Print the content of stack_a
		// ft_iter_node(stack_b, ft_print_int);

		// Free stack_a after you're done using it
		ft_free_stack2(stack_a);
	}
}