/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:19:27 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/12/07 20:11:57 by mjeyavat         ###   ########.fr       */
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

void	swap_x(t_opp *op)
{
	int			h_first;
	int			h_second;
	int			tresh_hold;
	int			cnt;

	h_first = 0;
	//h_second = 0;
	while (list_lenght(op, 1) > 0)
	{
		tresh_hold = 20;
		cnt = 0;
		//h_first = ft_findmin_val(op, cnt);
		h_second = ft_findrmin_val(op->stack_a, cnt);
		while (tresh_hold <= 100)
		{
			if (cnt < tresh_hold)
			{
				//h_second = ft_findrmin_val(op->stack_a, cnt);
				cnt++;
				//h_first = comp_data(op, h_first, ft_findmin_val(op, cnt));
				h_second = comp_data(op, h_second, ft_findrmin_val(op->stack_a, cnt));
			}
			//ft_printf("hold first: %d\n", h_second);
			//ft_printf("min value is %d\n", get_data_on_pos(op, h_second));
			//ft_printf("hold second: %d\n", h_second);
			tresh_hold += 20;
		}
		break ;
	}
	//ft_print_list(op);
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
		swap_x(op);
	//ft_printf("length of list: %d\n", ce);
	ft_printf("\n");
}
