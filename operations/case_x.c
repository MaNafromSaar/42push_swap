/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-05-14 15:09:43 by user              #+#    #+#             */
/*   Updated: 2024-05-14 15:09:43 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest)
{
    while (*a != cheapest->target && *b != cheapest)
        rr(a, b);
    indexing(*a);
    indexing(*b);
}

static void reverse_rotate_both(t_stack_node **a, t_stack_node **b, t_stack_node *cheapest)
{
    while (*a != cheapest->target && *b != cheapest)
        rrr(a, b);
    indexing(*a);
    indexing(*b);
}

/*static void move_a_to_b(t_stack_node **b, t_stack_node **a)
{
    t_stack_node *cheapest;

    cheapest = get_cheapest(*a);
    if(cheapest->above_median && cheapest->target->above_median)
        rotate_both(a, b, cheapest);
    else if (!cheapest->above_median && !cheapest->target->above_median)
        reverse_rotate_both(a, b, cheapest);
    else if (cheapest->above_median && !cheapest->target->above_median)
        rb(a);
    else if (!cheapest->above_median && cheapest->target->above_median)
        rrb(a);
    prep_push(b, cheapest, 'a');
}*/

static void move_b_to_a(t_stack_node **a, t_stack_node **b)
{
    t_stack_node *cheapest;

    cheapest = get_cheapest(*b);
    if(cheapest->above_median && cheapest->target->above_median)
        rotate_both(a, b, cheapest);
    else if (!cheapest->above_median && !cheapest->target->above_median)
        reverse_rotate_both(a, b, cheapest);
    else if (cheapest->above_median && !cheapest->target->above_median)
        rb(b);
    else if (!cheapest->above_median && cheapest->target->above_median)
        rrb(b);
    prep_push(a, cheapest, 'b');
}

static void min_on_top(t_stack_node **a)
{
    t_stack_node *min;

    min = find_min(*a);
    if (!min->above_median)
        ra(a);
    else if (min->above_median)
        rra(a);
}

void case_x(t_stack_node **a, t_stack_node **b)
{
    int len_a = stack_size(*a);

    if (len_a > 5)
    {
        while (--len_a > 5)
            pb(b, a);
        while (*b)
            move_b_to_a(a, b);
        while (stack_size(*a) > 5)
            min_on_top(a);
        case_5(a, b);
        while (*b)
            pa(a, b);
    }
    else if (len_a == 4)
        case_4(a, b);
    else if (len_a == 5)
        case_5(a, b);
}


        
