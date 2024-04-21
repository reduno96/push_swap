/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_nums_to_stack_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <reduno96@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 17:10:03 by rel-mora          #+#    #+#             */
/*   Updated: 2024/04/06 02:15:21 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	add_nums_to_stack(t_stack **stack_a, int argc, char **argv)
{
	t_var	idx;
	char	**strs;

	idx.i = 1;
	if (argc > 1)
	{
		while (idx.i < argc)
		{
			strs = ft_split(argv[idx.i++], ' ');
			if (!*strs)
				ft_error(*stack_a);
			idx.j = 0;
			while (strs[idx.j])
			{
				if (ft_check_num(strs[idx.j]) == 1)
					ft_add(stack_a, ft_new(ft_toi(strs[idx.j], *stack_a)));
				else
					ft_error(*stack_a);
				free(strs[idx.j++]);
			}
			free(strs);
		}
		ft_check_duplicate(*stack_a);
	}
}