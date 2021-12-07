/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:02:23 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/12/07 20:17:34 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_findmin_val(t_opp *op, int val)
{
	t_node	*tmp;
	int		i;

	tmp = op->stack_a;
	i = 0;
	while (tmp->next != NULL)
	{
		if (tmp->data == val)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int	ft_findrmin_val(t_node *stack, int val)
{
	static int	i;

	i = 0;
	if (stack != NULL)
	{
		ft_findrmin_val(stack->next, val);
		i++;
		if (val == stack->data)
		{
			val = stack->data;
			ft_printf("value found: %d\n", stack->data);
			ft_printf("postiion: %d\n", i);
			return (i);
		}
	}
	return (i);
}

int	get_data_on_pos(t_opp *op, int pos)
{
	int		data;
	t_node	*tmp;

	data = 0;
	tmp = op->stack_a;
	while (pos > 0)
	{
		tmp = tmp->next;
		data = tmp->data;
		pos--;
	}
	return (data);
}

/**
 * 1. nimm die zahl und vergleiche sie mit der n-1
*/
int	comp_data(t_opp *op, int minval_pos1, int minval_pos2)
{
	int	val_1;
	int	val_2;

	val_1 = get_data_on_pos(op, minval_pos1);
	val_2 = get_data_on_pos(op, minval_pos2);
	//ft_printf("value 1: %d\n", val_1);
	//ft_printf("value 2: %d\n", val_2);
	if (val_1 < val_2)
		return (minval_pos1);
	else
		return (minval_pos2);
}
