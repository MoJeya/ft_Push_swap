/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:02:23 by mjeyavat          #+#    #+#             */
/*   Updated: 2022/01/06 13:02:11 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	rotate_til(int val, t_opp *op, int option)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (option == 2)
	{
		while (i < val)
		{
			count += rra(&op->stack_a);
			i++;
		}
	}
	else if (option == 1)
	{
		while (i < val)
		{
			count += ra(&op->stack_a);
			i++;
		}
	}
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

//int	cal_and_rotate(int *h_1, int *h_2, t_opp *op)
//{
//	int	count;

//	count = 0;
//	if ((*h_1) < (list_lenght(op, 1) / 2) && (*h_2) < (list_lenght(op, 1) / 2))
//	{
//		if ((*h_1) < (*h_2) || (*h_1) == (*h_2))
//		{
//			count += rotate_til((*h_1), op, 1);
//		}
//		else if ((*h_1) > (*h_2))
//		{
//			count += rotate_til((*h_2), op, 1);
//		}
//		else if ((*h_2) < 0)
//			count += rotate_til((*h_1), op, 1);
//	}
//	ft_printf("pushed value: %d\n", op->stack_a->data);
//	count += pb(op);
//	(*h_1) = -1;
//	(*h_2) = -1;
//	return (count);
//}

//int	find_num_ver2(int chunck_x, t_opp *op, int *addi, int list_len)
//{
//	int		end;
//	t_node	*tmp;

//	tmp = op->stack_a;
//	set_chunck(&chunck_x, &end, list_len);
//	op->h1 = -1;
//	op->h2 = -1;
//	//ft_printf("starting TOTAL: %d\n", (*addi));
//	while (tmp != NULL)
//	{
//		if (tmp->data <= chunck_x && tmp->data >= end)
//		{
//			if (op->h1 == -1)
//				op->h1 = lst_find_pos(op, tmp->data, 1);
//			else if (op->h1 >= 0 && op->h2 == -1)
//				op->h2 = lst_find_pos(op, tmp->data, 1);
//		}
//		if (op->h1 != -1 && op->h2 != -1)
//			(*addi) += cal_and_rotate(&op->h1, &op->h2, op);
//		else if (op->h1 == -1 || op->h2 == -1)
//			tmp = tmp->next;
//	}
//	if (op->h1 >= 0 && op->h2 == -1)
//		(*addi) += cal_and_rotate(&op->h1, &op->h2, op);
//	else if (op->h2 >= 0 && op->h1 == -1)
//		(*addi) += cal_and_rotate(&op->h2, &op->h1, op);
//	//ft_printf("end TOTAL: %d\n", (*addi));
//	return (0);
//}

//void	get_pos(int *hold1, int	*hold2, t_opp *op, t_node *tmp)
//{
//	if ((*hold1) == -1)
//		(*hold1) = lst_find_pos(op, tmp->rank, 1);
//	else if ((*hold1) >= 0 && (*hold2) == -1)
//		(*hold2) = lst_find_pos(op, tmp->rank, 1);
//}

//void	find_num_ver2(t_opp *op, int *cnt, int r_start, int r_end)
//{
//	t_node	*tmp;
//	int		count;

//	op->h1 = -1;
//	op->h2 = -1;
//	tmp = op->stack_a;
//	count = 0;
//	while (tmp != NULL)
//	{
//		if (tmp->rank >= r_start && tmp->rank <= r_end)
//			get_pos(&op->h1, &op->h2, op, tmp);
//		if (op->h1 != -1 && op->h2 != -1)
//		{
//			(*cnt) += cal_and_rotate(&op->h1, &op->h2, op);
//			count++;
//		}
//		else if (op->h1 == -1 || op->h2 == -1)
//			tmp = tmp->next;
//		if (tmp->next == NULL)
//			tmp = op->stack_a;
//		if (count == r_end)
//			change_range(&r_start, &r_end);
//		if (count == 100)
//			break ;
//	}
//}
