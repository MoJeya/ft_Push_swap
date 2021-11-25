/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 12:08:56 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/11/25 20:52:53 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_pb(t_node **st_a, t_node **st_b)
{
	t_node	*head;

	if (!(*st_b))
	{
		(*st_b) = (*st_a);
		(*st_a) = (*st_a)->next;
		(*st_b)->next = NULL;
	}
	else
	{
		head = (*st_a);
		(*st_a) = (*st_a)->next;
		head->next = (*st_b);
		(*st_b) = head;
	}
	ft_print_list(*st_a, *st_b);
}

void	ft_pa(t_node **st_a, t_node **st_b)
{
	t_node	*head;

	if (!(*st_a))
	{
		(*st_a) = (*st_b);
		(*st_b) = (*st_b)->next;
		(*st_a)->next = NULL;
	}
	else
	{
		head = (*st_b);
		(*st_b) = (*st_b)->next;
		head->next = (*st_a);
		(*st_a) = head;
	}
	ft_print_list(*st_a, *st_b);
}
