/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-05-25 12:20:21 by user              #+#    #+#             */
/*   Updated: 2024-05-25 12:20:21 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int input_error(char *str)
 {
    if(!(ft_isdigit(*str) || *str == '-' || *str == '+' || (*str == '+' && ft_isdigit(*(str + 1))) || (*str == '-' && ft_isdigit(*(str + 1)))))
        return (1);
    while (*str++)
    {
        if (!ft_isdigit(*str))
            return (1);
    }
    return (0);
}

int duplicate_error(t_stack_node *stack, int data)
{
    while (stack)
    {
        if (!stack)
            return (0);
        if (stack->data == data)
            return (1);
        stack = stack->next;
    }
    return (0);
}

void free_stack(t_stack_node **stack)
{
    t_stack_node *tmp;

    while (*stack)
    {
        tmp = *stack;
        *stack = (*stack)->next;
        free(tmp);
    }
    *stack = NULL;
}

void error_handling(int argc, char **argv)
{
    t_stack_node *a;
    int i;

    a = NULL;
    i = 1;
    while (i < argc)
    {
        if (input_error(argv[i]))
        {
            write(1, "Error\n", 7);
            free_stack(&a);
            exit(1);
        }
        if (duplicate_error(a, atoi_long(argv[i])))
        {
            write(1, "Error\n", 7);
            free_stack(&a);
            exit(1);
        }
        i++;
    }
}