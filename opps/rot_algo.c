/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 15:33:29 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/11/28 18:32:37 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/*
	1. head should point to last from stack
	2. head->next should point to start from stack
	3. travers stack by one
*/

static t_node	*rotat_stack_down(t_node **stack)
{
	t_node	*head;
	t_node	*prv;

	prv = NULL;
	head = (*stack);
	while (head->next != NULL)
	{
		prv = head;
		head = head->next;
	}
	prv->next = NULL;
	head->next = (*stack);
	(*stack) = head;
	return ((*stack));
}

static t_node	*rotat_stack_up(t_node **stack)
{
	t_node	*lastnode;
	t_node	*newnode;

	newnode = create_node((*stack)->data);
	(*stack) = (*stack)->next;
	lastnode = (*stack);
	while (lastnode->next != NULL)
	{
		lastnode = lastnode->next;
	}
	lastnode->next = newnode;
	return (lastnode);
}

void	ft_r_rotat(t_node **stack_a, char aorb)
{
	if (aorb == 'A' || aorb == 'a')
		ft_printf("rra\n");
	else if (aorb == 'B' || aorb == 'b')
		ft_printf("rrb\n");
	rotat_stack_down(stack_a);
}

void	ft_rotat(t_node **stack, char aorb)
{
	if (aorb == 'A' || aorb == 'a')
		ft_printf("ra\n");
	else if (aorb == 'B' || aorb == 'b')
		ft_printf("rb\n");
	rotat_stack_up(stack);
}
