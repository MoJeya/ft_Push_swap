/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:02:23 by mjeyavat          #+#    #+#             */
/*   Updated: 2022/01/03 17:55:58 by mjeyavat         ###   ########.fr       */
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
	ft_printf("count roation value: %d\n", count);
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
		if (h_1 < h_2 || h_1 == h_2)
		{
			count += rotate_til(h_1, op, 1);
		}
		else if (h_1 > h_2 && h_2 != -1)
		{
			count += rotate_til(h_2, op, 1);
		}
		else if (h_2 < 0)
			count += rotate_til(h_1, op, 1);
	}
	ft_printf("Push to STACK B: %d\n", data_on_pos(op, 0, 1));
	count += pb(op);
	//ft_printf("Rotation_operartion TOTAL: %d\n", count);
	ft_printf("count: %d\n", count);
	return (count);
}

int	find_num_ver2(int chunck_x, t_opp *op, int *addi, int list_len)
{
	int		end;
	int		h1;
	int		h2;
	t_node	*tmp;

	ft_printf("begin op cost: %d\n", (*addi));
	tmp = op->stack_a;
	if (list_len == 100)
		pick_set(&chunck_x, &end, list_len);
	else if (list_len == 500)
		pick_set_500(&chunck_x, &end, list_len);
	h1 = -1;
	h2 = -1;
	while (tmp != NULL)
	{
		if (tmp->data <= chunck_x && tmp->data >= end)
		{
			if (h1 == -1)
				h1 = lst_find_pos(op, tmp->data, 1);
			else if (h1 >= 0 && h2 == -1)
				h2 = lst_find_pos(op, tmp->data, 1);
		}
		if (h1 != -1 && h2 != -1)
		{
			ft_printf("Hold 1: %d\nHold 2: %d\n", h1, h2);
			(*addi) += cal_and_rotate(h1, h2, op);
			h1 = -1;
			h2 = -1;
		}
		else if (h1 == -1 || h2 == -1)
			tmp = tmp->next;
	}
	if (h1 >= 0 && h2 == -1)
	{
		ft_printf("Hold 1: %d\n", h1);
		(*addi) += cal_and_rotate(h1, -1, op);
	}
	else if (h1 == -1 && h2 >= 0)
	{
		(*addi) += cal_and_rotate(h2, -1, op);
	}
	ft_printf("find_num opperations cost: %d\n", (*addi));
	return (0);
}
