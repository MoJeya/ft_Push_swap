/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:02:23 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/12/17 14:01:01 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

//int	ft_findmin_val(t_opp *op, int val)
//{
//	t_node	*tmp;
//	int		lst_len;
//	int		i;

//	tmp = op->stack_a;
//	i = 0;
//	lst_len = list_lenght(op, 1);
//	while (tmp->next != NULL)
//	{
//		if (tmp->data == val)
//			return (i);
//		tmp = tmp->next;
//		i++;
//	}
//	if (i == list_lenght(op, 1))
//		return (100);
//	return (i);
//}
void rrotate_til(int val, t_opp *op)
{
	int	i;

	i = 0;
	while (i < val)
	{
		ft_revrot(&op->stack_a);
		i++;
	}
}

void	rotate_til(int val, t_opp *op)
{
	int	i;

	i = 0;
	while (i < val)
	{
		ft_rot(&op->stack_a);
		i++;
	}
}

int	get_data_on_pos(t_opp *op, int pos)
{
	int		data;
	t_node	*tmp;

	data = 0;
	tmp = op->stack_a;
	if (pos == 0)
		return (tmp->data);
	while (pos > 0)
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
		if (h_1 < h_2)
			rotate_til(h_1, op);
		else if (h_1 > h_2)
			rotate_til (h_2, op);
	}
	else if (h_1 > (list_lenght(op, 1) / 2) && h_2 > (list_lenght(op, 1) / 2))
	{
		h_1 = list_lenght(op, 1) - h_1;
		h_2 = list_lenght(op, 1) - h_2;
		if (h_1 < h_2)
			rrotate_til(h_1, op);
		else if (h_1 > h_2)
			rrotate_til(h_2, op);
	}
	else if (h_1 < (list_lenght(op, 1) / 2) && h_2 > (list_lenght(op, 1) / 2))
	{
		h_2 = list_lenght(op, 1) - h_2;
		if (h_1 < h_2)
			rotate_til(h_1, op);
		else if (h_1 > h_2)
			rrotate_til(h_2, op);
	}
	pb(op);
}

void	pick_set(int *chunk_x, int *end)
{
	if ((*chunk_x) == 0)
		(*end) = 19;
	else if ((*chunk_x) == 1)
	{
		(*chunk_x) = 20;
		(*end) = 39;
	}
	else if ((*chunk_x) == 2)
	{
		(*chunk_x) = 40;
		(*end) = 59;
	}
	else if ((*chunk_x) == 3)
	{
		(*chunk_x) = 60;
		(*end) = 79;
	}
	else if ((*chunk_x) == 4)
	{
		(*chunk_x) = 80;
		(*end) = 99;
	}
}

int	find_num(int chunck_x, int count, t_opp *op)
{
	int		i;
	int		end;
	int		h_1;
	int		h_2;

	end = 0;
	pick_set(&chunck_x, &end);
	i = chunck_x;
	h_1 = -1;
	h_2 = -1;
	while (i < end)
	{
		count = i;
		while (count < end)
		{
			h_1 = lst_find_pos(op, count);
			ft_printf("h_1: %d\nh_2: %d\ncount: %d\n", h_1, h_2, count); // der fehler liegt in der lst_find_pos
			while (h_1 >= 0 && count < end)
			{
				h_2 = lst_find_pos(op, count);
				count++;
				if (h_2 >= 0)
					break ;
			}
			if (h_1 >= 0 && h_2 >= 0)
				break ;
			count++;
		}
		if (list_lenght(op, 1) == 1)
			return (0);
		if (h_1 >= 0 && h_2 >= 0)
		{
			ft_printf("h_1 = %d\nh_2 = %d\n", h_1, h_2);
			cal_and_rotate(h_1, h_2, op);
			h_1 = -1;
			h_2 = -1;
			i = chunck_x;
		}
		else if (h_1 < 0 && h_2 < 0)
			return (0);
		i++;
	}
	return (0);
}
