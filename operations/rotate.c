/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-05-14 09:04:17 by user              #+#    #+#             */
/*   Updated: 2024-05-14 09:04:17 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_stack_node **stack)
{
    t_stack_node *first;
    t_stack_node *last;

    if (*stack == NULL || (*stack)->next == NULL)
        return; 

    first = *stack;
    *stack = (*stack)->next;
    first->next = NULL;

    last = *stack;
    while (last->next != NULL)
        last = last->next;
    last->next = first;
}

void    ra(t_stack_node **a)
{
    rotate(a);
    write(1, "ra\n", 3);
}

void    rb(t_stack_node **b)
{
    rotate(b);
    write(1, "rb\n", 3);
}

void    rr(t_stack_node **a, t_stack_node **b)
{
    rotate(a);
    rotate(b);
    write(1, "rr\n", 3);
}