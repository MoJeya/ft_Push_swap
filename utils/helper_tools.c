/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:24:37 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/12/18 20:47:15 by mjeyavat         ###   ########.fr       */
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

int	max_n(t_opp *op)
{
	t_node	*tmp;
	int		max_val;

	tmp = op->stack_b;
	max_val = tmp->data;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		if (max_val < tmp->data)
			max_val = tmp->data;
	}
	return (max_val);
}

int	min_n(t_opp *op)
{
	t_node	*tmp;
	int		min_val;

	tmp = op->stack_a;
	min_val = tmp->data;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
		if (min_val > tmp->data)
			min_val = tmp->data;
	}
	return (min_val);
}

int	lst_find_pos(t_opp *op, int val)
{
	t_node	*tmp;
	int		pos;
	int		first_num;

	tmp = op->stack_a;
	pos = 0;
	first_num = tmp->data;
	while (tmp != NULL && (tmp->data != val))
	{
		pos++;
		tmp = tmp->next;
	}
	if (tmp != NULL && first_num != val && val != tmp->data)
	{
		ft_printf("Nothing found\n pos: %d\n", pos);
		return (-1);
	}
	return (pos);
}

int	is_num_lst(t_opp *op, int num)//!mistake
{
	int		flag;
	t_node	*tmp;

	tmp = op->stack_a;
	flag = 0;
	while (tmp != NULL)
	{
		if (tmp->data == num)
		{
			flag = 0;
			break ;
		}
		else
			flag = 1;
		tmp = tmp->next;
	}
	if (flag == 0)
		ft_printf("Number: %d true\n");
	else if (flag == 1)
		ft_printf("Number %d false\n");
	return (flag);
}
