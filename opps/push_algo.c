/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 12:08:56 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/11/27 15:31:50 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	pop_stack(t_node **st_from, t_node **st_to)
{
	t_node	*head;

	if (!(*st_to))
	{
		(*st_to) = (*st_from);
		(*st_from) = (*st_from)->next;
		(*st_to)->next = NULL;
	}
	else
	{
		head = (*st_from);
		(*st_from) = (*st_from)->next;
		head->next = (*st_to);
		(*st_to) = head;
	}
}

void	ft_pb(t_node **st_a, t_node **st_b)
{
	//ft_printf("pb\n");
	pop_stack(st_a, st_b);
	ft_print_list(*st_a, *st_b);
}

void	ft_pa(t_node **st_a, t_node **st_b)
{
	//ft_printf("pa\n");
	pop_stack(st_b, st_a);
	ft_print_list(*st_a, *st_b);
}
