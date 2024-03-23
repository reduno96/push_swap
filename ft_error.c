// #include "push_swap.h"

// void	ft_free_stack(int arr)
// {
// 	if (arr)
// 		free(arr);
// }
// void	ft_putchar_fd(char c, int fd)
// {
// 	write(fd, &c, 1);
// }
// void	ft_putstr_fd(char *s, int fd)
// {
// 	int	i;

// 	if (!s)
// 		return ;
// 	i = 0;
// 	while (s[i])
// 	{
// 		ft_putchar_fd(s[i++], fd);
// 	}
// }
// void	ft_putendl_fd(char *s, int fd)
// {
// 	if (!s)
// 		return ;
// 	ft_putstr_fd(s, fd);
// 	ft_putchar_fd('\n', fd);
// }

// void	ft_error(t_stack *stack_a)
// {
// 	ft_free_stack(stack_a->content);
// 	ft_putendl_fd("Error", 2);
// 	exit(0);
// }
