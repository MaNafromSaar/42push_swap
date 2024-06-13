/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-05-13 09:16:25 by user              #+#    #+#             */
/*   Updated: 2024-05-13 09:16:25 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int main(int argc, char **argv)
{
    t_stack_node    *a;
    t_stack_node    *b;

    a = NULL;
    b = NULL;
    if (argc == 1 || (argc == 2 && !argv[1][0]))
        return (1);
    else if (argc == 2)
        argv = split(argv[1], ' ');
    initialize_stack(&a, argc, argv);
    t_stack_node *current = a;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
    if (stack_is_sorted(a))
        return (0);
    if (stack_size(a) == 2)
        sa(&a);
    else if (stack_size(a) == 3)
        case_3(&a);
    else if (stack_size(a) == 4)
        case_4(&a, &b);
    else if (stack_size(a) == 5)
        case_5(&a, &b);
    else
        case_x(&a, &b);
    current = a;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
    return (0);
}