/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-05-13 09:30:56 by user              #+#    #+#             */
/*   Updated: 2024-05-13 09:30:56 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long atoi_long(const char *s)
{
    long    res;
    int     sign;

    res = 0;
    sign = 1;
    while ((*s >= 9 && *s <= 13) || *s == 32)
        s++;    
    if (*s == '-' || *s == '+')
    {
        if (*s == '-')
            sign = -1;
        s++;
    }
    while (ft_isdigit(*s))
    {
        res = res * 10 + *s - '0';
        s++;
    }   
    return (res * sign);
}

static void append_node(t_stack_node **stack, long data)
{
    t_stack_node    *new_node;
    t_stack_node    *last;

    new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
    if (!new_node)
        exit(1);
    new_node->data = data;
    new_node->next = NULL;
    new_node->prev = NULL;
    if (!*stack)
    {
        *stack = new_node;
        return ;
    }
    last = *stack;
    while (last->next)
        last = last->next;
    last->next = new_node;
    new_node->prev = last;
}

void initialize_stack(t_stack_node **stack, int argc, char **argv)
{
    int i;
    long data;

    i = 1;
    while (i < argc)
    {
        data = atoi_long(argv[i]);
        append_node(stack, data);
        i++;
    }
}

t_stack_node *cheapest_cost(t_stack_node *a, t_stack_node *b)
{
    t_stack_node *node;
    t_stack_node *cheapest;

    node = a;
    cheapest = a;
    while (node)
    {
        if (node->data < cheapest->data)
            cheapest = node;
        node = node->next;
    }
    node = b;
    while (node)
    {
        if (node->data < cheapest->data)
            cheapest = node;
        node = node->next;
    }
    return (cheapest);
}

void prep_push(t_stack_node **stack, t_stack_node *node, char stack_name)
{
    t_stack_node *tmp;

    tmp = *stack;
    while (tmp)
    {
        if (tmp == node)
            break;
        tmp = tmp->next;
    }
    if (!tmp)
        return ;
    if (tmp->above_median && stack_name == 'a')
            ra(stack);
    else if (!tmp->above_median && stack_name == 'a')
            rra(stack);
    else if (tmp->above_median && stack_name == 'b')
            rb(stack);
    else if (!tmp->above_median && stack_name == 'b')
            rrb(stack);
}