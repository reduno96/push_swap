/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rules_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rel-mora <rel-mora@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:59:49 by rel-mora          #+#    #+#             */
/*   Updated: 2024/03/26 23:06:06 by rel-mora         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void    ft_swap(t_stack **stack_a)
{
    t_stack *fst;
    t_stack *scd;

    if (*stack_a == NULL || (*stack_a)->next == NULL)
        return ;
    fst = *stack_a;
    scd = (*stack_a)->next;
    if (scd->next != NULL)
        scd->next->prev = fst;
    fst->next = scd->next;
    scd->next = fst;
    fst->prev = scd;
    scd->prev = NULL;
    *stack_a = scd;
}

// void ft_swap_a_b(t_stack *stack_a, t_stack *stack_b)
// {
//     ft_swap(stack_a);
//     ft_swap(stack_b);
// }

void ft_push_a(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *fst_b;


    if (*stack_b == NULL)
        return ;
    fst_b = *stack_b;
    *stack_b = (*stack_b)->next;
    if (*stack_b != NULL)
        (*stack_b)->prev = NULL;
    fst_b->prev = NULL;
    *stack_a = fst_b;
}

void ft_push_b(t_stack **stack_a, t_stack **stack_b)
{
    t_stack *fst_a;


    if (*stack_a == NULL)
        return ;
    fst_a = *stack_a;
    *stack_a = (*stack_a)->next;
    if (*stack_a != NULL)
        (*stack_a)->prev = NULL;
    fst_a->prev = NULL;
    *stack_b = fst_a;
}

void  ft_rotate(t_stack **stack)
{
    t_stack *first;
    t_stack *last;

    if (!(*stack) || !(*stack)->next)
        return ;
    first = *stack;
    last = ft_last_node(*stack);
    *stack = first->next;
    last->next =first;
    first->prev = last;
    first->next = NULL;
    (*stack)->prev = NULL;
}