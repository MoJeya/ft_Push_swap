/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:35:03 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/11/18 18:05:19 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	init_list_a(t_node *stack_a, int num)
{
	t_node	*current;

	current = stack_a;
	while (current != NULL)
	{
		stack_a->data = num;
		current = current->next;
		//printf("[%d]", stack_a->data);
	}
}

void	inti_list_b(t_node *stack_b)
{
	t_node	*current;

	current = stack_b;
	while (current != NULL)
	{
		stack_b->data = 0;
		current = current->next;
	}
}

/*
 * This function should initzialase nodes on
	a list
*/
