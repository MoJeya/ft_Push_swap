/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:19:27 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/12/02 23:00:31 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap_five(t_opp *op)
{
	int		pos_min;

	pos_min = lst_find_pos(op, min_n(op));
	while (pos_min > 0)
	{
		ft_rot(&op->stack_a);
		pos_min--;
	}
	ft_pb(op);
	pos_min = lst_find_pos(op, min_n(op));
	while (pos_min > 0)
	{
		ft_rot(&op->stack_a);
		pos_min--;
	}
	ft_pb(op);
	swap_three(op);
	ft_pa(op);
	ft_pa(op);
}

void	swap_three(t_opp *op)
{
	int	pos_max;
	int	pos_min;

	pos_max = lst_find_pos(op, max_n(op));
	pos_min = lst_find_pos(op, min_n(op));
	if (pos_min == 1 && pos_max == 2)
		ft_sa(op);
	else if (pos_min == 2 && pos_max == 0)
	{
		ft_sa(op);
		ft_revrot(&op->stack_a);
	}
	else if (pos_min == 1 && pos_max == 0)
		ft_rot(&op->stack_a);
	else if (pos_min == 0 && pos_max == 1)
	{
		ft_sa(op);
		ft_rot(&op->stack_a);
	}
	else if (pos_min == 2 && pos_max == 1)
		ft_revrot(&op->stack_a);
	ft_printf("\n");
}

void	check_which_op(t_opp *op)
{
	int	ce;

	ce = list_lenght(op);
	if (ce == 3)
		swap_three(op);
	if (ce == 5)
		swap_five(op);
	//else
	//	ft_swap_x(&op->stack_a, &op->stack_b);
	//ft_printf("length of list: %d\n", ce);
}
