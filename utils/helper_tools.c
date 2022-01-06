/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:24:37 by mjeyavat          #+#    #+#             */
/*   Updated: 2022/01/06 12:49:51 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	list_lenght(t_opp *op, int stack_option)
{
	int		len;
	t_node	*tmp;

	tmp = NULL;
	len = 0;
	if (stack_option == 1)
		tmp = op->stack_a;
	else if (stack_option == 2)
		tmp = op->stack_b;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		len++;
	}
	return (len);
}

int	max_n(t_opp *op, int option)
{
	t_node	*tmp;
	int		max_val;

	tmp = NULL;
	if (option == 2)
		tmp = op->stack_b;
	else if (option == 1)
		tmp = op->stack_a;
	max_val = tmp->rank;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		if (max_val < tmp->rank)
			max_val = tmp->rank;
	}
	//ft_printf("The Biggest value: %d\n", max_val);
	return (max_val);
}

int	min_n(t_opp *op)
{
	t_node	*tmp;
	int		min_val;

	tmp = op->stack_a;
	min_val = tmp->rank;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		if (min_val > tmp->rank)
			min_val = tmp->rank;
	}
	return (min_val);
}

int	lst_find_pos(t_opp *op, int val, int option)
{
	t_node	*tmp;
	int		pos;
	int		first_num;

	tmp = NULL;
	if (option == 1)
		tmp = op->stack_a;
	else if (option == 2)
		tmp = op->stack_b;
	pos = 0;
	first_num = tmp->rank;
	while (tmp != NULL && (tmp->rank != val))
	{
		pos++;
		tmp = tmp->next;
	}
	if (tmp != NULL && first_num != val && val != tmp->rank)
		return (-1);
	return (pos);
}

//int	is_num_lst(t_opp *op, int num)
//{
//	int		flag;
//	t_node	*tmp;

//	tmp = op->stack_a;
//	flag = 0;
//	while (tmp != NULL)
//	{
//		if (tmp->data == num)
//		{
//			flag = 0;
//			break ;
//		}
//		else
//			flag = 1;
//		tmp = tmp->next;
//	}
//	return (flag);
//}
