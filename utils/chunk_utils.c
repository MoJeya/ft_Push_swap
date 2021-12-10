/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:02:23 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/12/10 15:39:17 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_findmin_val(t_opp *op, int val)
{
	t_node	*tmp;
	int		lst_len;
	int		i;

	tmp = op->stack_a;
	i = 0;
	lst_len = list_lenght(op, 1);
	while (tmp->next != NULL)
	{
		if (tmp->data == val)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (i);
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

/**
 * 1. nimm die zahl und vergleiche sie mit der n-1
*/
int	comp_data(t_opp *op, int minval_pos1, int minval_pos2)
{
	int	val_1;
	int	val_2;
	//ft_printf("minval_pos1: %d\n", minval_pos1);
	//ft_printf("minval_pos2: %d\n", minval_pos2);
	if (minval_pos1 < 0)
	{
		val_2 = get_data_on_pos(op, minval_pos2);
		val_1 = get_data_on_pos(op, 0);
		//ft_printf("X_val_1 = %d\n", val_1);
	}
	else if (minval_pos2 < 0)
	{
		val_1 = get_data_on_pos(op, minval_pos1);
		val_2 = get_data_on_pos(op, 0);
		//ft_printf("X_val_2 = %d\n", val_2);
	}
	else
	{
		val_1 = get_data_on_pos(op, minval_pos1);
		val_2 = get_data_on_pos(op, minval_pos2);
		//ft_printf("A:value 1: %d\n", val_1);
		//ft_printf("A:value 2: %d\n", val_2);
	}
	if (val_1 < val_2)
		return (minval_pos1);
	else
		return (minval_pos2);
}
