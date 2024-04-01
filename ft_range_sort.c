/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <reduno96@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 03:27:29 by rel-mora          #+#    #+#             */
/*   Updated: 2024/04/01 03:30:39 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	ft_babel_sort(int *array, int len)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len - i - 1)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

int	ft_find_index(int *array, int len, int num)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (array[i] == num)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_indexing(t_stack **stack_a, t_stack **stack_b)
{
	int		len;
	t_var	idx;
	t_stack	*tmp;
	int		*array;

	(void)stack_b;
	len = ft_stack_len(stack_a);
	array = malloc(len * 4);
	tmp = *stack_a;
	while (idx.i < len)
	{
		array[idx.i++] = tmp->content;
		tmp = tmp->next;
	}
	ft_babel_sort(array, len);
	tmp = *stack_a;
	while (tmp != NULL)
	{
		tmp->index = ft_find_index(array, len, tmp->content);
		tmp = tmp->next;
	}
	free(array);
}
