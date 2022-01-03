/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:19:27 by mjeyavat          #+#    #+#             */
/*   Updated: 2022/01/03 17:11:03 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap_five(t_opp *op)
{
	int		pos_min;

	pos_min = lst_find_pos(op, min_n(op), 1);
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
	pb(op);
	pos_min = lst_find_pos(op, min_n(op), 1);
	while (pos_min > 0)
	{
		ft_rot(&op->stack_a);
		pos_min--;
	}
	pb(op);
	swap_three(op);
	pa(op);
	pa(op);
}

void	swap_three(t_opp *op)
{
	int	pos_max;
	int	pos_min;

	pos_max = lst_find_pos(op, max_n(op, 1), 1);
	pos_min = lst_find_pos(op, min_n(op), 1);
	if (pos_min == 1 && pos_max == 2)
		sa(op);
	else if (pos_min == 2 && pos_max == 0)
	{
		sa(op);
		ft_revrot(&op->stack_a);
	}
	else if (pos_min == 1 && pos_max == 0)
		ft_rot(&op->stack_a);
	else if (pos_min == 0 && pos_max == 1)
	{
		sa(op);
		ft_rot(&op->stack_a);
	}
	else if (pos_min == 2 && pos_max == 1)
		ft_revrot(&op->stack_a);
}

int	push_back_a(t_opp *op)
{
	int	h1;
	int	cnt;
	int	opps_cost;

	h1 = 0;
	cnt = 0;
	opps_cost = 0;
	while (list_lenght(op, 2) > 0)
	{
		cnt = 0;
		h1 = lst_find_pos(op, max_n(op, 2), 2);
		if (h1 > list_lenght(op, 2) / 2)
		{
			h1 = list_lenght(op, 2) - h1;
			while (cnt < h1)
			{
				opps_cost += ft_revrot(&op->stack_b);
				cnt++;
			}
		}
		else if (h1 <= list_lenght(op, 2) / 2)
		{
			while (cnt < h1)
			{
				opps_cost += ft_rot(&op->stack_b);
				cnt++;
			}
		}
		opps_cost += pa(op);
	}
	ft_printf("Rotation Cost: %d\n", opps_cost);
	return (opps_cost);
}

void	swap_100(t_opp *op)
{
	int	num;
	int	end;
	int	addi;
	int	list_len;

	num = 0;
	end = 0;
	list_len = list_lenght(op, 1);
	if (list_len == 100)
		end = list_len / 20;
	else if (list_len == 500)
		end = list_len / 50;
	addi = 0;
	while (num < end)
	{
		ft_printf("=====================chunk %d\n", num);
		if (find_num_ver2(num, op, &addi, list_len) == 0)
		{
			num++;
		}
	}
	addi += push_back_a(op);
	ft_printf("Opperation cost = %d\n", addi);
}

void	check_which_op(t_opp *op)
{
	int	ce;

	ce = list_lenght(op, 1);
	if (ce == 3)
		swap_three(op);
	else if (ce == 5)
		swap_five(op);
	else if (ce == 100 || ce == 500)
	{
		swap_100(op);
	}
	ft_print_list(op);
	ft_printf("list lenght: %d\n", list_lenght(op, 1));
}
