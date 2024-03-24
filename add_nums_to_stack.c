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

void	ft_print_list(int content)
{
	printf("%d\n", content);
}
int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
static char	**free_ptrs(char **ptr, int i)
{
	while (i > 0)
	{
		i--;
		free(ptr[i]);
	}
	free(ptr);
	return (0);
}

static int	count_world(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			count++;
			while (s[i] != c && s[i])
				i++;
		}
	}
	return (count);
}

static int	len_word(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static char	**ft_fill(char const *s, char c, char **str)
{
	int	i;
	int	j;

	i = 0;
	while (*s)
	{
		if (*s != c && *s)
		{
			str[i] = malloc((len_word(s, c) + 1) * sizeof(char));
			if (!str[i])
				return (free_ptrs(str, i));
			j = 0;
			while (*s != c && *s)
			{
				str[i][j++] = *s;
				s++;
			}
			str[i++][j] = '\0';
		}
		while (*s == c && *s)
			s++;
	}
	str[i] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**str;

	if (!s)
		return (NULL);
	count = count_world(s, c);
	str = malloc((count + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	str = ft_fill(s, c, str);
	return (str);
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
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_check_duplicate(char *str)
{
	int	i;
	int	j;

	i = 1;
	while (str[i])
	{
		j = 0;
		while (str[j])
		{
			if (str[i] == str[j] && i != j)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
int	ft_check(char *str)
{
	if (ft_check_num(str) == 1)
		return (1);
	else if (ft_check_duplicate(str) == 1)
		return (1);
	return (0);
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

t_stack	*ft_new_node(int content)
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
void	ft_add_node(t_stack **stack, t_stack *new_node)
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

void	add_nums_to_stack(int argc, char **argv)
{
	int		i;
	t_stack	*stack_a;

	i = 1;
	stack_a = NULL;
	if (argc > 1)
	{
		while (i < argc)
		{
			if (ft_check_num(argv[i]) == 1)
				ft_add_node(&stack_a, ft_new_node(ft_toi(argv[i], stack_a)));
			else
				ft_error(stack_a);
			i++;
		}
		ft_iter_node(stack_a, ft_print_list);
	}
}
