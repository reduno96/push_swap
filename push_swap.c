/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <reduno96@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 21:39:19 by rel-mora          #+#    #+#             */
/*   Updated: 2024/03/24 17:24:06 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack *stack_a;

	stack_a = NULL;
	if (argc > 1)
	{
		add_nums_to_stack(stack_a, argc, argv);
		printf("stack: %d\n", stack_a->content);
	}
}