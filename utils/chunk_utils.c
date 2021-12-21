/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:02:23 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/12/21 14:46:50 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	rotate_til(int val, t_opp *op, int option)
{
	int	i;
	int count;

	i = 0;
	count = 0;
	if (option == 2)
	{
		while (i < val)
		{
			count += ft_revrot(&op->stack_a);
			i++;
		}
	}
	else if (option == 1)
	{
		while (i < val)
		{
			count += ft_rot(&op->stack_a);
			i++;
		}
	}
	//ft_printf("Pushed Value: %d\n", op->stack_a->data);
	return (count);
}

int	data_on_pos(t_opp *op, int pos, int option)
{
	int		data;
	t_node	*tmp;

	data = 0;
	tmp = NULL;
	if (option == 1)
		tmp = op->stack_a;
	else if (option == 2)
		tmp = op->stack_b;
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

int	cal_and_rotate(int h_1, int h_2, t_opp *op)
{
	int	count;

	count = 0;
	if (h_1 < (list_lenght(op, 1) / 2) && h_2 < (list_lenght(op, 1) / 2))
	{
		//ft_printf("OPTION 1\n");
		if (h_1 < h_2 || h_1 == h_2)
			count += rotate_til(h_1, op, 1);
		else if (h_1 > h_2)
			count += rotate_til (h_2, op, 1);
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
			count += rotate_til(h_1, op, 2);
		else if (h_1 > h_2)
			count += rotate_til(h_2, op, 2);
	}
	else if (h_1 < (list_lenght(op, 1) / 2) && h_2 > (list_lenght(op, 1) / 2))
	{
		//ft_printf("OPTION 3\n");
		h_2 = list_lenght(op, 1) - h_2;
		if (h_1 < h_2)
			count += rotate_til(h_1, op, 1);
		else if (h_1 > h_2)
			count += rotate_til(h_2, op, 2);
	}
	else if (h_1 > (list_lenght(op, 1) / 2) && h_2 < (list_lenght(op, 1) / 2))
	{
		//ft_printf("OPTION 4\n");
		h_1 = list_lenght(op, 1) - h_1;
		if (h_1 == 0)
			h_1 = 1;
		//ft_printf("ROTATE COST 1: %d\nROTATE COST 2: %d\n", h_1, h_2);
		if (h_1 < h_2)
			count += rotate_til(h_1, op, 2);
		else if (h_1 > h_2)
			count += rotate_til(h_2, op, 1);
		else
		{
			//ft_printf("OPTION 5\nROTATE COST 1 & 2: %d & %d\n", h_1, h_2);
			count += rotate_til(h_1, op, 2);
		}
	}
	count += pb(op);
	//ft_printf("count: %d\n", count);
	return (count);
}

//int	find_num(int chunck_x, t_opp *op, int *addi)
//{
//	int		i;
//	int		end;
//	int		h_1;
//	int		h_2;
//	int		cnt;
//	int		count;

//	end = 0;
//	if (list_lenght(op, 1) == 100)
//		pick_set(&chunck_x, &end);
//	else if (list_lenght(op, 1) == 500)
//		pick_set_500(&chunck_x, &end);
//	i = chunck_x;
//	h_1 = -1;
//	h_2 = -1;
//	cnt = chunck_x;
//	count = 0;
//	while (i < end && list_lenght(op, 1) > 0)
//	{
//		if (chunck_x == 0)
//			cnt = chunck_x + i;
//		else
//			cnt = chunck_x + (i % chunck_x);
//		while (cnt < end + 1)
//		{
//			if (is_num_lst(op, cnt) == 0)
//			{
//				if (h_1 < 0)
//					h_1 = lst_find_pos(op, cnt, 1);
//				else if (h_1 >= 0 && h_2 < 0)
//				{
//					h_2 = lst_find_pos(op, cnt, 1);
//					count += cal_and_rotate(h_1, h_2, op);
//					h_1 = -1;
//					h_2 = -1;
//					break ;
//				}
//			}
//			cnt++;
//		}
//		if (is_num_lst(op, i) == 0)
//			i -= 1;
//		i++;
//	}
//	(*addi) += count;
//	return (0);
//}

int	find_num_ver2(int chunck_x, t_opp *op, int *addi)
{
	int	end;
	int	h1;
	int	h2;
	int	i;
	t_node *tmp;

	tmp = op->stack_a;
	if (list_lenght(op, 1) == 100)
	{
		pick_set(&chunck_x, &end, op);
		ft_printf("start: %d\nend: %d\n", chunck_x, end);
	}
	else if (list_lenght(op, 1) == 500)
		pick_set_500(&chunck_x, &end, op);
	h1 = -1;
	h2 = -1;
	i = 0;
	while (i < list_lenght(op, 1))
	{
		if (tmp && tmp->data < chunck_x && tmp->data >= end)
		{
			ft_printf("data: %d\n", tmp->data);
			if (h1 == -1)
				h1 = lst_find_pos(op, tmp->data, 1);
			else if (h1 >= 0 && h2 == -1)
				h2 = lst_find_pos(op, tmp->data, 1);
		}
		if (h1 != -1 && h2 != -1)
		{
			ft_printf("h1: %d\nh2: %d\ndata on h1: %d\ndata 0n h2: %d\n", h1, h2, data_on_pos(op, h1, 1), data_on_pos(op, h2, 1));
			(*addi) += cal_and_rotate(h1, h2, op);
			h1 = -1;
			h2 = -1;
		}
		else if (h1 == -1 && h2 == -1 && tmp->next == NULL)
			return (0);
		if (tmp->next == NULL)
			tmp = op->stack_a;
		else
			tmp = tmp->next;
		i++;
	}
	return (0);
}
