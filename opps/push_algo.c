/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 12:08:56 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/11/29 14:21:32 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	pop_stack(t_node **st_from, t_node **st_to)
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

void	ft_pb(t_opp *opp)
{
	pop_stack(&opp->stack_a, &opp->stack_b);
}

void	ft_pa(t_opp *opp)
{
	pop_stack(&opp->stack_b, &opp->stack_a);
}
