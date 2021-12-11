/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:19:27 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/12/11 19:52:58 by mjeyavat         ###   ########.fr       */
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

/*
 * TODO: make the swap_100 function more flexible so it can sort more or less than 100 values
 ////fix loop
 *	////problem ist dass es am kurz vorm ende nicht richtig sortiert weil
 *	////die liste selbst nicht größer als 20 ist und deshalb der rest der Liste
 *	////mit Trash memory gefült wird, dass führt dazu das die zahlen mit mül verglichen werden
 *	////und deswegen die Opperationen nicht mehr stimmen.
*/

int	search_min(int start_val, int end_val, t_opp *op, int *opp_total)
{
	int	num;
	int	count;
	int	pos;

	count = 0;
	while (count < 20 && list_lenght(op,1) != 0)
	{
		num = start_val;
		pos = ft_findmin_val(op, num);
		while (num < end_val)
		{
			if (get_data_on_pos(op, pos) > end_val)
			{
				num++;
				pos = comp_data(op, pos, ft_findmin_val(op, num));
			}
			num++;
			pos = comp_data(op, pos, ft_findmin_val(op, num));
		}
		if (pos < list_lenght(op, 1) / 2 || pos == 0)
		{
			while (pos > 0)
			{
				ft_rot(&op->stack_a);
				(*opp_total)++;
				pos--;
			}
			(*opp_total)++;
			ft_pb(op);
		}
		else if (pos >= list_lenght(op, 1) / 2)
		{
			while (pos < list_lenght(op, 1))
			{
				ft_revrot(&op->stack_a);
				(*opp_total)++;
				pos++;
			}
			ft_pb(op);
			(*opp_total)++;
		}
		count++;
	}
	ft_printf("The opperations TOTAL at the Moment ist %d\n", (*opp_total));
	return (0);
}

void	swap_100(t_opp *op)
{
	int		main_loop;
	int		cnt;
	int		opp_total;

	main_loop = 20;
	cnt = 0;
	opp_total = 0;
	while (list_lenght(op, 1) > 0)
	{
		if (search_min(cnt, main_loop, op, &opp_total) == 0)
		{
			cnt = main_loop;
			main_loop += 20;
		}
		if (main_loop == 120)
			break ;
	}
	if (list_lenght(op, 2) != 0)
	{
		cnt = list_lenght(op,2);
		while (cnt > 0)
		{
			ft_pa(op);
			opp_total++;
			cnt--;
		}
	}
	ft_printf("The TOTAL opperations cost are: %d\n", opp_total);
}

void	check_which_op(t_opp *op)
{
	int	ce;

	ce = list_lenght(op, 1);
	if (ce == 3)
		swap_three(op);
	else if (ce == 5)
		swap_five(op);
	else
		swap_100(op);
	ft_print_list(op);
}
