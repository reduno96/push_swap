/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <reduno96@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 21:39:19 by rel-mora          #+#    #+#             */
/*   Updated: 2024/03/24 22:24:56 by rel-mora         ###   ########.fr       */
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

	if (argc > 1)
	{
		stack_a = add_nums_to_stack(argc, argv);
		ft_iter_node(stack_a, ft_print_int);
		// Print the content of stack_a
		ft_free_stack2(stack_a);
		// Free stack_a after you're done using it
	}
}