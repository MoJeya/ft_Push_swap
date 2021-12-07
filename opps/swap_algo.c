/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/27 15:03:51 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/12/06 18:59:29 by mjeyavat         ###   ########.fr       */
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

	if (!(*st_from) || (*st_from)->next == NULL)
	{
		return ((*st_from));
	}
	else
	{
		temp = (*st_from)->data;
		(*st_from)->data = (*st_from)->next->data;
		(*st_from)->next->data = temp;
	}
	return ((*st_from));
}

void	ft_sa(t_opp *opp)
{
	swap_stack(&opp->stack_a);
	//ft_printf("sa ");
}

void	ft_sb(t_opp *opp)
{
	swap_stack(&opp->stack_b);
}

void	ft_ss(t_opp *opp)
{
	swap_stack(&opp->stack_a);
	swap_stack(&opp->stack_b);
}
