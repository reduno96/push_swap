/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range_sort_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <reduno96@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/01 03:27:29 by rel-mora          #+#    #+#             */
/*   Updated: 2024/05/13 15:09:44 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	find_index_by_value(t_stack *stack, int value)
{
	t_stack	*current;
	int		pos;

	current = stack;
	pos = 0;
	while (current != NULL)
	{
		if (current->content == value)
			return (pos);
		current = current->next;
		pos++;
	}
	return (-1);
}

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
