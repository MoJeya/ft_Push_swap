/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:19:27 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/12/14 19:55:15 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap_five(t_opp *op)
{
	int		pos_min;

	pos_min = lst_find_pos(op, min_n(op));
	if (pos_min == 4)
		ft_revrot(&op->stack_a);
	else
	{
		while (pos_min > 0)
		{
			ft_rot(&op->stack_a);
			pos_min--;
		}
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

	ft_printf("2\n");
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
}

void	swap_100(t_opp *op)
{
	int	chunk1;
	int	chunk2;
	int	count1;
	int	count2;

	chunk1 = list_lenght(op, 1) / 4;
	chunk2 = chunk1 + list_lenght(op, 1) / 4;
	count1 = 0;
	count2 = chunk1;
	while (list_lenght(op, 1) > 1)
	{
		if (count1 == chunk1 || count2 == chunk2)
		{
			if (count1 == chunk1)
				chunk1 = chunk2;
			if (count2 == chunk2)
				chunk2 += 25;
		}
		ft_serach_through(count1, op);
		ft_serach_through(count2, op);
		if (op->stack_a->next == NULL)
			comp_data(op);
		count1++;
		count2++;
	}
}

void	check_which_op(t_opp *op)
{
	int	ce;
	int	max;
	int	pos;

	ce = list_lenght(op, 1);
	if (ce == 3)
		swap_three(op);
	else if (ce == 5)
		swap_five(op);
	else if (ce == 100)
	{
		swap_100(op);
		// this should be packed in a separate function also the sorting is still not correct
		while (op->stack_b != NULL)
		{
			max = max_n(op);
			pos = lst_find_pos(op, max);
			ft_printf("Max Number: %d\nPosition: %d\n", max, pos);
			rotate_to_val(pos, op, 2);
			ft_pa(op);
		}
	}
	ft_print_list(op);
}
