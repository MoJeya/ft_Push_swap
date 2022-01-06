/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:03:51 by mjeyavat          #+#    #+#             */
/*   Updated: 2022/01/06 13:50:38 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/**
 * swap the first two elements at the top of stack A and if stack A is empty or
 * has only one element then it should do nothing
*/

static t_node	*swap_stack(t_node **st_from)
{
	int	temp;
	int	rank_tmp;

	if (!(*st_from) || (*st_from)->next == NULL)
	{
		return ((*st_from));
	}
	else
	{
		temp = (*st_from)->data;
		rank_tmp = (*st_from)->rank;
		(*st_from)->data = (*st_from)->next->data;
		(*st_from)->rank = (*st_from)->next->rank;
		(*st_from)->next->data = temp;
		(*st_from)->next->rank = rank_tmp;
	}
	return ((*st_from));
}

int	sa(t_node *stack_a)
{
	swap_stack(&stack_a);
	write(1, "sa\n", 3);
	return (1);
}

int	sb(t_node *stack_b)
{
	swap_stack(&stack_b);
	write(1, "sb\n", 3);
	return (1);
}

int	ss(t_opp *opp)
{
	swap_stack(&opp->stack_a);
	swap_stack(&opp->stack_b);
	write(1, "ss\n", 3);
	return (1);
}
