/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 18:24:37 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/12/02 22:18:32 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	list_lenght(t_opp *op)
{
	int		len;
	t_node	*tmp;

	len = 0;
	tmp = op->stack_a;
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
		//if (tmp->next == NULL)
		//	break ;
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
		//if (tmp->next == NULL)
		//	break ;
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
