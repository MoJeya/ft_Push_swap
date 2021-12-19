/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 15:33:29 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/12/19 20:32:05 by mjeyavat         ###   ########.fr       */
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
	if (!(*stack) || (*stack)->next == NULL)
		return ((*stack));
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
/**
 * !hat leak
*/

static t_node	*rotat_stack_up(t_node **stack)
{
	t_node	*lastnode;
	t_node	*newnode;

	newnode = create_node((*stack)->data);
	if (!(*stack) || (*stack)->next == NULL)
		return ((*stack));
	(*stack) = (*stack)->next;
	lastnode = (*stack);
	while (lastnode->next != NULL)
	{
		lastnode = lastnode->next;
	}
	lastnode->next = newnode;
	return (lastnode);
}

int	ft_revrot(t_node **stack)
{
	rotat_stack_down(stack);
	return (1);
}

int	ft_rot(t_node **stack)
{
	rotat_stack_up(stack);
	return (1);
}

int	ft_rr(t_opp *opp)
{
	ft_rot(&opp->stack_a);
	ft_rot(&opp->stack_b);
	return (1);
}
