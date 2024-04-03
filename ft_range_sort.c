/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <reduno96@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 03:27:29 by rel-mora          #+#    #+#             */
/*   Updated: 2024/04/03 03:21:11 by rel-mora         ###   ########.fr       */
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

void	ft_indexing(t_stack *stack_a)
{
	int		len;
	t_var	idx;
	t_stack	*tmp;
	int		*array;

	len = ft_stack_len(&stack_a);
	array = malloc(len * sizeof(int));
	if (!array)
		return ;
	tmp = stack_a;
	idx.i = 0;
	while (idx.i < len)
	{
		array[idx.i++] = tmp->content;
		tmp = tmp->next;
	}
	ft_babel_sort(array, len);
	tmp = stack_a;
	while (tmp != NULL)
	{
		tmp->index = ft_find_index(array, len, tmp->content);
		tmp = tmp->next;
	}
	free(array);
}
