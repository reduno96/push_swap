#include "push_swap.h"
void	del(void *content)
{
	free(content);
}

void	ft_del_node(t_stack *stack_a)
{
	if (!stack_a)
		return ;
	// del(stack_a);
	free(stack_a);
}

void	ft_free_stack(t_stack **stack)
{
	t_stack	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		ft_del_node(*stack);
		*stack = tmp;
	}
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		ft_putchar_fd(s[i++], fd);
	}
}

void	ft_putendl_fd(char *s, int fd)
{
	if (!s)
		return ;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}

void	ft_error(t_stack *stack_a)
{
            

	ft_free_stack(&stack_a);
	stack_a = NULL;
	ft_putendl_fd("Error", 2);
	exit(0);
}
