/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:02:23 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/12/18 21:04:04 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rotate_til(int val, t_opp *op, int option)
{
	int	i;

	i = 0;
	if (option == 2)
	{
		while (i < val)
		{
			ft_revrot(&op->stack_a);
			i++;
		}
	}
	else if (option == 1)
	{
		while (i < val)
		{
			ft_rot(&op->stack_a);
			i++;
		}
	}
	ft_printf("Pushed Value: %d\n", op->stack_a->data);
}

int	data_on_pos(t_opp *op, int pos)
{
	int		data;
	t_node	*tmp;

	data = 0;
	tmp = op->stack_a;
	if (pos == 0)
		return (tmp->data);
	while (pos > 0 && tmp->next != NULL)
	{
		tmp = tmp->next;
		data = tmp->data;
		pos--;
	}
	if (pos < 0)
		return (tmp->data);
	return (data);
}

void	cal_and_rotate(int h_1, int h_2, t_opp *op)
{
	if (h_1 < (list_lenght(op, 1) / 2) && h_2 < (list_lenght(op, 1) / 2))
	{
		//ft_printf("OPTION 1\n");
		if (h_1 < h_2 || h_1 == h_2)
			rotate_til(h_1, op, 1);
		else if (h_1 > h_2)
			rotate_til (h_2, op, 1);
	}
	else if (h_1 > (list_lenght(op, 1) / 2) && h_2 > (list_lenght(op, 1) / 2))
	{
		//ft_printf("OPTION 2\n");
		h_1 = list_lenght(op, 1) - h_1;
		h_2 = list_lenght(op, 1) - h_2;
		if (h_1 == 0)
			h_1 = 1;
		else if (h_2 == 0)
			h_2 = 1;
		//ft_printf("ROTATE COST 1: %d\nROTATE COST 2: %d\n", h_1, h_2);
		if (h_1 < h_2 || h_1 == h_2)
			rotate_til(h_1, op, 2);
		else if (h_1 > h_2)
			rotate_til(h_2, op, 2);
	}
	else if (h_1 < (list_lenght(op, 1) / 2) && h_2 > (list_lenght(op, 1) / 2))
	{
		//ft_printf("OPTION 3\n");
		h_2 = list_lenght(op, 1) - h_2;
		if (h_1 < h_2)
			rotate_til(h_1, op, 1);
		else if (h_1 > h_2)
			rotate_til(h_2, op, 2);
	}
	else if (h_1 > (list_lenght(op, 1) / 2) && h_2 < (list_lenght(op, 1) / 2))
	{
		//ft_printf("OPTION 4\n");
		h_1 = list_lenght(op, 1) - h_1;
		if (h_1 == 0)
			h_1 = 1;
		//ft_printf("ROTATE COST 1: %d\nROTATE COST 2: %d\n", h_1, h_2);
		if (h_1 < h_2)
			rotate_til(h_1, op, 2);
		else if (h_1 > h_2)
			rotate_til(h_2, op, 1);
		else
		{
			//ft_printf("OPTION 5\nROTATE COST 1 & 2: %d & %d\n", h_1, h_2);
			rotate_til(h_1, op, 2);
		}
	}
	pb(op);
}

int	find_num(int chunck_x, t_opp *op)
{
	int		i;
	int		end;
	int		h_1;
	int		h_2;
	int		cnt;

	end = 0;
	pick_set(&chunck_x, &end);
	i = chunck_x;
	h_1 = -1;
	h_2 = -1;
	cnt = chunck_x;
	while (i < end)
	{
		ft_printf("i: %d\n", i);
		if (chunck_x == 0)
			cnt = chunck_x + i;
		else
			cnt = chunck_x + (i % chunck_x);
		ft_printf("cnt: %d\n", cnt);
		while (cnt < end + 1)
		{
			if (is_num_lst(op, cnt) == 0)
			{
				if (h_1 < 0)
					h_1 = lst_find_pos(op, cnt);
				else if (h_1 >= 0 && h_2 < 0)
				{
					h_2 = lst_find_pos(op, cnt);
					//ft_printf("h_1: %d\nh_2: %d\n", h_1, h_2);
					//ft_printf("h_1 value: %d\nh_2 value: %d\n", data_on_pos(op, h_1), data_on_pos(op, h_2));
					cal_and_rotate(h_1, h_2, op);
					h_1 = -1;
					h_2 = -1;
					break ;
				}
			}
			cnt++;
		}
		ft_printf("value: %d is on %d\n", i, data_on_pos(op, i));
		if (is_num_lst(op, i) == 0)
		{
			i -= 1;
		}
		i++;
	}
	return (0);
}
