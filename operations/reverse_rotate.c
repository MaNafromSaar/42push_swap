/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-05-14 09:09:41 by user              #+#    #+#             */
/*   Updated: 2024-05-14 09:09:41 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void reverse_rotate(t_stack_node **stack)
{
    t_stack_node *last;
    t_stack_node *first;

    if (!*stack || !(*stack)->next)
        return;

    first = *stack;
    last = *stack;
    while (last->next)
        last = last->next;

    last->prev->next = NULL;
    last->prev = NULL;
    last->next = first;
    first->prev = last;
    *stack = last;
}

void    rra(t_stack_node **a)
{
    reverse_rotate(a);
    write(1, "rra\n", 4);
}

void    rrb(t_stack_node **b)
{
    reverse_rotate(b);
    write(1, "rrb\n", 4);
}

void    rrr(t_stack_node **a, t_stack_node **b)
{
    reverse_rotate(a);
    reverse_rotate(b);
    write(1, "rrr\n", 4);
}