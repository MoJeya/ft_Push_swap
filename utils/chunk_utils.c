/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:02:23 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/12/15 13:38:45 by mjeyavat         ###   ########.fr       */
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
	if (i == list_lenght(op, 1))
		return (100);
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

void	rotate_to_val(int pos, t_opp *opp, int stack_option, int *total)
{
	int	cnt;

	cnt = 0;
	if (pos < (list_lenght(opp, stack_option) / 2))
	{
		while (cnt < pos)
		{
			if (stack_option == 1)
				ft_rot(&opp->stack_a);
			else if (stack_option == 2)
				ft_rot(&opp->stack_b);
			cnt++;
			(*total)++;
		}
	}
	else
	{
		cnt = pos;
		while (cnt <= list_lenght(opp, stack_option))
		{
			if (stack_option == 1)
				ft_revrot(&opp->stack_a);
			else if (stack_option == 2)
				ft_revrot(&opp->stack_b);
			cnt++;
			(*total)++;
		}
	}
}

void	comp_data(t_opp *op, int *total)
{
	if (op->stack_a != NULL)
	{
		if (list_lenght(op, 2) == 0)
			pb(op);
		else if (op->stack_a->data > op->stack_b->data)
		{
			//ft_printf("stack a: %d > stack b: %d\n", op->stack_a->data, op->stack_b->data);
			pb(op);
			ft_rot(&op->stack_b);
		}
		else if (op->stack_a->data < op->stack_b->data)
		{
			pb(op);
		}
	}
	(*total)++;
}

void	ft_serach_through(int val, t_opp *op, int *total)
{
	int	i;
	int	pos;

	i = val;
	pos = 0;
	if (ft_findmin_val(op, i) < list_lenght(op, 1)
		&& ft_findmin_val(op, i) != 100)
	{
		pos = ft_findmin_val(op, i);
		rotate_to_val(pos, op, 1, total);
		comp_data(op, total);
	}
}
