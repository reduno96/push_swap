# include "push_swap.h"

void    ft_swap(t_stack *stack_a)
{
    int tmp;

    if (stack_a && stack_a->next)
    {
        tmp = stack_a->content;
        stack_a->content = stack_a->next->content;
        stack_a->next->content = tmp;
    }
}

void ft_swap_a_b(t_stack *stack_a, t_stack *stack_b)
{
    ft_swap(stack_a);
    ft_swap(stack_b);
}

void ft_push_b(t_stack *stack_a, t_stack *stack_b)
{
    t_stack *tmp;

    if (stack_b)
    {
        tmp = stack_b;
        stack_b = (stack_b)->next;
        tmp->next = stack_a;
        stack_a = tmp;
        printf("red");
    }

}