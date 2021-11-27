/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:03:51 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/11/27 16:51:50 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/**
 * swap the first two elements at the top of stack A and if stack A is empty or
 * has only one element then it should do nothing
*/

t_node	*swap_stack(t_node **st_from)
{
	t_node	*head;

	head = NULL;
	head = malloc(sizeof(t_node));
	if (!(*st_from) || (*st_from)->next == NULL)
	{
		return ((*st_from));
	}
	else
	{
		head->data = (*st_from)->data;
		(*st_from)->data = (*st_from)->next->data;
		(*st_from)->next->data = head->data;
	}
	return (head);
}

void	ft_sa(t_node **st_a)
{
	ft_printf("sa\n");
	swap_stack(st_a);
}

void	ft_sb(t_node **st_b)
{
	ft_printf("sb\n");
	swap_stack(st_b);
}

void	ft_ss(t_node **st_a, t_node **st_b)
{
	ft_printf("ss\n");
	swap_stack(st_a);
	swap_stack(st_b);
}
