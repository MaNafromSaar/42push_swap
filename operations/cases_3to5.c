/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-05-13 18:40:22 by user              #+#    #+#             */
/*   Updated: 2024-05-13 18:40:22 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void case_3(t_stack_node **a) 
{
    t_stack_node *max;
    if (stack_is_sorted(*a) || stack_size(*a) != 3) 
        return;
    max = find_max(*a);
    if ((*a)->data == max->data)
        ra(a);
    else if ((*a)->next->data == max->data)
        rra(a);
    if ((*a)->data > (*a)->next->data)
        sa(a);
}

void case_4(t_stack_node **a, t_stack_node **b) 
{
    t_stack_node *min_node;
    if (stack_is_sorted(*a) || stack_size(*a) != 4)
        return;
    min_node = find_min(*a);
    while ((*a)->data != min_node->data)
        ra(a);
    pb(a, b);
    case_3(a);
    pa(a, b);
}


void case_5(t_stack_node **a, t_stack_node **b)
{
    t_stack_node *min_node;

    if (stack_is_sorted(*a))
        return;
    min_node = find_min(*a);
    if (!min_node)
        return;
    while ((*a)->data != min_node->data)
        ra(a);
    pb(a, b);
    case_4(a, b);
    pa(a, b);
}