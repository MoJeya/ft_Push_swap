/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/19 12:08:56 by mjeyavat          #+#    #+#             */
/*   Updated: 2022/01/10 18:04:49 by mjeyavat         ###   ########.fr       */
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

int	pb(t_opp *opp)
{
	pop_stack(&opp->stack_a, &opp->stack_b);
	write(1, "pb\n", 3);
	return (1);
}

int	pa(t_opp *opp)
{
	pop_stack(&opp->stack_b, &opp->stack_a);
	write(1, "pa\n", 3);
	return (1);
}

void	put_stack_back(t_opp *op)
{
	//1. pushe alles von b nach a bis auf das letzte
	while (op->stack_b->next != NULL)
		pa(op);
	//2. schau ob stack_b noch ein wert hat
	if (list_lenght(op, 2) == 1)
		pa(op);
}