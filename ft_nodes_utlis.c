/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nodes_utlis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <reduno96@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/24 16:18:19 by rel-mora          #+#    #+#             */
/*   Updated: 2024/03/24 17:23:20 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_iter_node(t_stack *lst, void (*f)(int))
{
	t_stack	*node;

	if (!lst || !f)
		return ;
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
	if (!stack)
		return (NULL);
	while (last->next != NULL)
		last = last->next;
	return (last);
}

void	ft_add(t_stack **stack, t_stack *new_node)
{
	t_stack	*last;

	if (!stack || !new_node)
		return ;
	if (*stack == NULL)
	{
		*stack = new_node;
	}
	else
	{
		last = ft_last_node(*stack);
		last->next = new_node;
		new_node->prev = last;
	}
}
