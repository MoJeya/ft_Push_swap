/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/28 15:33:29 by mjeyavat          #+#    #+#             */
/*   Updated: 2022/01/13 18:05:32 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_node	*rotat_stack_down(t_node **stack)
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

t_node	*ft_last(t_node *lst)
{
	while (lst)
	{
		if (lst && !lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

t_node	*rotat_stack_up(t_node **stack)
{
	t_node	*tmp;

	tmp = ft_last(*stack);
	tmp->next = *stack;
	tmp = *stack;
	*stack = (*stack)->next;
	tmp->next = NULL;
	return (*stack);
}
