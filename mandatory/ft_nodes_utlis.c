/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodes_utlis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <rel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:18:19 by rel-mora          #+#    #+#             */
/*   Updated: 2024/05/14 12:17:18 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_iter_node(t_stack *lst, void (*f)(int))
{
	t_stack	*node;

	node = lst;
	while (node != NULL)
	{
		f(node->content);
		node = node->next;
	}
}

t_stack	*ft_new(int content)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->content = content;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

t_stack	*ft_last_node(t_stack *stack)
{
	t_stack	*last;

	last = stack;
	while (last->next != NULL)
		last = last->next;
	return (last);
}

void	ft_add(t_stack **stack, t_stack *new_node)
{
	t_stack	*last;

	if (*stack == NULL)
		*stack = new_node;
	else
	{
		last = ft_last_node(*stack);
		last->next = new_node;
		new_node->prev = last;
	}
}

int	ft_stack_len(t_stack **stack_a)
{
	int		len;
	t_stack	*tmp;

	len = 0;
	tmp = *stack_a;
	while (tmp != NULL)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}
