/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:35:03 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/11/19 12:49:26 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_node	*init_list_a(t_node *stack_a, int num)
{
	t_node	*current;

	current = stack_a;
	while (current != NULL)
	{
		stack_a->data = num;
		current = current->next;
		//printf("[%d]", stack_a->data);
	}
	return (current);
}

t_node	*inti_list_b(t_node *stack_b)
{
	t_node	*current;

	current = stack_b;
	while (current != NULL)
	{
		stack_b->data = 0;
		current = current->next;
	}
	return (current);
}

void	ft_print_list(t_node *st_a, t_node *st_b)
{
	t_node	*tmp_a;
	t_node	*tmp_b;

	ft_printf("Stack A:				Stack B\n");
	tmp_a = st_a;
	tmp_b = st_b;
	while (tmp_a != NULL)
	{
		if (tmp_a->next == NULL)
			ft_printf("[%d]				[%d]\n", tmp_a->data, tmp_b->data);
		else
			ft_printf("[%d]				[%d]\n", tmp_a->data, tmp_b->data);
		tmp_a = tmp_a->next;
	}
}

/*
 * This function should initzialase nodes on
	a list
*/
