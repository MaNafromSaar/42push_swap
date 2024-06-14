/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: user <user@student.42.fr>                  #+#  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2024-05-13 14:30:56 by user              #+#    #+#             */
/*   Updated: 2024-05-13 14:30:56 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


/*static void	push(t_stack_node **dst, t_stack_node **src)
{
	t_stack_node	*node_to_push;
	if (!*src)
		return ;
	node_to_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	node_to_push->prev = NULL;
	if (!*dst)
	{
		*dst = node_to_push;
		node_to_push->next = NULL;
	}
	else
	{
		node_to_push->next = *dst;
		node_to_push->next->prev = node_to_push;
		*dst = node_to_push;
	}
}*/

void	pa(t_stack_node **a, t_stack_node **b)
{
	t_stack_node    *top;

	if (*b == NULL)
		return ;
	top = *b;
	*b = (*b)->next;
	top->next = *a;
	*a = top;
}

void	pb(t_stack_node **a, t_stack_node **b)
{
	t_stack_node *top;

	if (*a == NULL)
		return ;
	top = *a;
	*a = (*a)->next;
	top->next = *b;
	*b = top;
}