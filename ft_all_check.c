/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <rel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:20:51 by rel-mora          #+#    #+#             */
/*   Updated: 2024/03/26 21:31:54 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_duplicate(t_stack *stack_a)
{
	t_stack	*node;
	t_stack	*tmp;

	node = stack_a;
	while (node != NULL)
	{
		tmp = node->next;
		while (tmp != NULL)
		{
			if (node->content == tmp->content)
				ft_error(stack_a);
			tmp = tmp->next;
		}
		node = node->next;
	}
	return (1);
}

int	ft_toi(const char *str, t_stack *stack_a)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	if ((result > 2147483648 && sign == -1) || (result > 2147483647
			&& sign == 1))
		ft_error(stack_a);
	return ((int)(result * sign));
}

int	ft_check_num(char *str)
{
	size_t	i;
	size_t	j;
	char	**strs;

	strs = ft_split(str, ' ');
	i = 0;
	j = 0;
	while (strs[i])
	{
		while (strs[i][j])
		{
			if (ft_isdigit(strs[i][j]) == 0)
			{
				return (ft_free_split(strs), 0);
			}
			j++;
		}
		i++;
	}
	i = 0;
	return (ft_free_split(strs), 1);
}
