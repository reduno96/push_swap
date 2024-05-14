/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <rel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 21:39:19 by rel-mora          #+#    #+#             */
/*   Updated: 2024/05/14 12:14:52 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_check_instruction(char *read_line)
{
	if (!ft_strcmp(read_line, "sa\n") || !ft_strcmp(read_line, "sb\n")
		|| !ft_strcmp(read_line, "ss\n") || !ft_strcmp(read_line, "pa\n")
		|| !ft_strcmp(read_line, "pb\n") || !ft_strcmp(read_line, "ra\n")
		|| !ft_strcmp(read_line, "rb\n") || !ft_strcmp(read_line, "rr\n")
		|| !ft_strcmp(read_line, "rra\n") || !ft_strcmp(read_line, "rrb\n")
		|| !ft_strcmp(read_line, "rrr\n"))
		return (1);
	return (0);
}

void	ft_validate_one(t_stack **stack_a, t_stack **stack_b, char *read_line)
{
	if (!ft_strcmp(read_line, "sa\n"))
		ft_swap(stack_a);
	else if (!ft_strcmp(read_line, "sb\n"))
		ft_swap(stack_b);
	else if (!ft_strcmp(read_line, "ss\n"))
	{
		ft_swap(stack_a);
		ft_swap(stack_b);
	}
	else if (!ft_strcmp(read_line, "pa\n"))
		ft_push(stack_a, stack_b);
	else if (!ft_strcmp(read_line, "pb\n"))
		ft_push(stack_b, stack_a);
}

void	ft_validate_two(t_stack **stack_a, t_stack **stack_b, char *read_line)
{
	if (!ft_strcmp(read_line, "ra\n"))
		ft_rotate(stack_a);
	else if (!ft_strcmp(read_line, "rb\n"))
		ft_rotate(stack_b);
	else if (!ft_strcmp(read_line, "rr\n"))
	{
		ft_rotate(stack_a);
		ft_rotate(stack_b);
	}
	else if (!ft_strcmp(read_line, "rra\n"))
		ft_reverse_rotate(stack_a);
	else if (!ft_strcmp(read_line, "rrb\n"))
		ft_reverse_rotate(stack_b);
	else if (!ft_strcmp(read_line, "rrr\n"))
	{
		ft_reverse_rotate(stack_a);
		ft_reverse_rotate(stack_b);
	}
}

void	ft_read_stack(t_stack **stack_a, t_stack **stack_b)
{
	char	*read_line;

	read_line = get_next_line(0);
	while (read_line)
	{
		if (ft_check_instruction(read_line))
		{
			ft_validate_one(stack_a, stack_b, read_line);
			ft_validate_two(stack_a, stack_b, read_line);
		}
		else
		{
			free(read_line);
			ft_free_stack2(*stack_a);
			ft_free_stack2(*stack_b);
			ft_putstr_fd("Error\n", 2);
			exit(0);
		}
		free(read_line);
		read_line = get_next_line(0);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		add_nums_to_stack(&stack_a, argc, argv);
		ft_read_stack(&stack_a, &stack_b);
		if (stack_a != NULL && ft_is_sorted(stack_a) == 1 && stack_b == NULL)
		{
			ft_free_stack2(stack_a);
			ft_free_stack2(stack_b);
			ft_putstr_fd("OK\n", 1);
		}
		else
		{
			ft_free_stack2(stack_a);
			ft_free_stack2(stack_b);
			ft_putstr_fd("KO\n", 1);
		}
	}
}
