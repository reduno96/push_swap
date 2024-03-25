#include "push_swap.h"


t_stack	*ft_lstlast(t_list *lst)
{
	t_stack	*last;

	last = lst;
	if (!lst)
		return (NULL);
	while (last->next != NULL)
		last = last->next;
	return (last);
}

void ft_add_node(t_stack **stack, int content)
{

    t_stack *last;
    if (!stack)
		return ;
    if (*stack == NULL)
        *stack = 



}

