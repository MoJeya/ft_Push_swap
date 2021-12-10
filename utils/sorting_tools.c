/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:19:27 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/12/10 16:38:31 by mjeyavat         ###   ########.fr       */
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

/**
 * TODO: erveything between row 92 and … should be packed in a function
 *
*/
int	search_min(int start_val, int end_val, t_opp *op)
{
	int	num;
	int	count;
	int	pos;

	count = 0;
	while (count < 20)
	{
		num = start_val;
		pos = ft_findmin_val(op, num);
		//ft_printf("FIRST VALUE STACK: 0[%d]\nNUMBER TO FIND: %d\nFOUND AT: %d\nVALUE AT FOUND INDEX: %d\n", op->stack_a->data, num, pos, get_data_on_pos(op, pos));
		while (num < end_val)
		{
			if (get_data_on_pos(op, pos) > end_val)
			{
				//ft_printf("Number to big!\n");
				num++;
				pos = comp_data(op, pos, ft_findmin_val(op, num));
			}
			num++;
			pos = comp_data(op, pos, ft_findmin_val(op, num));
		}
		if (pos < list_lenght(op, 1) / 2)
		{
			//ft_printf("VALUE TO SET: %d\n",pos);
			while (pos > 0)
			{
				ft_rot(&op->stack_a);
				pos--;
			}
			ft_pb(op);
		}
		else if (pos > list_lenght(op, 1) / 2)
		{
			while (pos < list_lenght(op, 1))
			{
				ft_revrot(&op->stack_a);
				pos++;
			}
			ft_pb(op);
		}
		count++;
		//ft_printf("count: %d\n", count);
		//ft_print_list(op);
	}
	return (0);
}

void	swap_x(t_opp *op)
{
	int		main_loop;
	int		cnt;
	int		end_loop;

	main_loop = 20;
	cnt = 0;
	end_loop = 0;
	while (list_lenght(op, 1) > 0)
	{
		ft_printf("list lenght: %d\n", list_lenght(op,1));
		if (search_min(cnt, main_loop, op) == 0)
		{
			cnt = main_loop;
			main_loop += 20;
		}
		if (main_loop == 120)
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
