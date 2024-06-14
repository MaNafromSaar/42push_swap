/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: user <user@student.42.fr>                  #+#  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2024-05-13 18:40:22 by user              #+#    #+#             */
/*   Updated: 2024-05-13 18:40:22 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


void	case_3(t_stack_node **a)
{
	t_stack_node *max;

	if (stack_is_sorted(*a) || stack_size(*a) != 3)
		return ;
	max = find_max(*a);
	if ((*a)->data == max->data)
		ra(a);
	else if ((*a)->next->data == max->data)
		rra(a);
	if ((*a)->data > (*a)->next->data)
		sa(a);
}

void	case_4(t_stack_node **a, t_stack_node **b)
{
	t_stack_node *min;

	if (stack_is_sorted(*a) || stack_size(*a) != 4)
		return ;
	min = find_min(*a);
	if ((*a)->data != min->data)
	{
		while ((*a)->data != min->data)
			ra(a);
	}
	pb(a, b);
	if (stack_size(*a) == 3 && !stack_is_sorted(*a))
		case_3(a);
	pa(a, b);
}

void	case_5(t_stack_node **a, t_stack_node **b)
{
	t_stack_node *min;

	if (stack_is_sorted(*a))
		return ;
	min = find_min(*a);
	if ((*a)->data != min->data)
	{
		while ((*a)->data != min->data)
			ra(a);
	}
	pb(a, b);
	while (*a != NULL)
	{
		printf("%d ", (*a)->data);
		*a = (*a)->next;
	}
	if (stack_size(*a) == 4 && !stack_is_sorted(*a))
		case_4(a, b);
	while (a != NULL)
	{
		printf("%d ", (*a)->data);
		*a = (*a)->next;
	}
	// pa(a, b);
}