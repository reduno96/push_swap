/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_nums_to_stack.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <rel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 17:10:03 by rel-mora          #+#    #+#             */
/*   Updated: 2024/03/26 21:38:48 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


t_stack	*add_nums_to_stack(int argc, char **argv)
{
	int		i;
	int		j;
	char	**strs;
	t_stack	*stack_a;

	stack_a = NULL;
	i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			strs = ft_split(argv[i++], ' ');
			if (!*strs)
				return(ft_error(stack_a),NULL);
			j = 0;
			while (strs[j])
			{
				if (ft_check_num(strs[j]) == 1)
					ft_add(&stack_a, ft_new(ft_toi(strs[j], stack_a)));
				else
					ft_error(stack_a);
				free(strs[j++]);
			}
			free(strs);
		}
	}
	return (ft_check_duplicate(stack_a), stack_a);
}
