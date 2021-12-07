/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:24:37 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/12/06 19:05:31 by mjeyavat         ###   ########.fr       */
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

	tmp = op->stack_a;
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

	tmp = op->stack_a;
	pos = 0;
	while (tmp != NULL && (tmp->data != val))
	{
		pos++;
		tmp = tmp->next;
	}
	return (pos);
}

void	set_top_b(t_node **stack, int pos, int mid_val)
{
	if (pos < mid_val)
	{
		while (pos > 0 && (*stack) != NULL)
		{
			ft_rot(stack);
			pos--;
		}
	}
	else if (pos > mid_val)
	{
		while (pos < 99 && (*stack) != NULL)
		{
			ft_revrot(stack);
			pos++;
		}
	}
}

