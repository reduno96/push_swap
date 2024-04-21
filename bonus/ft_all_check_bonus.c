/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all_check_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <rel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:20:51 by rel-mora          #+#    #+#             */
/*   Updated: 2024/04/21 12:35:14 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] == s2[i])
			i++;
		else
			break ;
	}
	return (s1[i] - s2[i]);
}
