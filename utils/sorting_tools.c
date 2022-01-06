/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 18:19:27 by mjeyavat          #+#    #+#             */
/*   Updated: 2022/01/06 14:22:39 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap_five(t_opp *op)
{
	int		pos_min;

	pos_min = lst_find_pos(op, min_n(op), 1);
	if (pos_min == 4)
		rra(&op->stack_a);
	else
	{
		while (pos_min > 0)
		{
			ra(&op->stack_a);
			pos_min--;
		}
	}
	pb(op);
	pos_min = lst_find_pos(op, min_n(op), 1);
	while (pos_min > 0)
	{
		ra(&op->stack_a);
		pos_min--;
	}
	pb(op);
	swap_three(op);
	pa(op);
	pa(op);
}

void	swap_three(t_opp *op)
{
	int	pos_max;
	int	pos_min;

	pos_max = lst_find_pos(op, max_n(op, 1), 1);
	pos_min = lst_find_pos(op, min_n(op), 1);
	if (pos_min == 1 && pos_max == 2)
		sa(op->stack_a);
	else if (pos_min == 2 && pos_max == 0)
	{
		sa(op->stack_a);
		rra(&op->stack_a);
	}
	else if (pos_min == 1 && pos_max == 0)
		ra(&op->stack_a);
	else if (pos_min == 0 && pos_max == 1)
	{
		sa(op->stack_a);
		ra(&op->stack_a);
	}
	else if (pos_min == 2 && pos_max == 1)
		rra(&op->stack_a);
}

int	is_sorted_a(t_opp *op)
{
	t_node	*current;

	current = op->stack_a;
	while (current->next != NULL)
	{
		if (current->rank < current->next->rank)
			current = current->next;
		else
			break ;
	}
	if (current->next == NULL)
	{
		ft_printf("Everything is sorted\n");
		exit(0);
	}
	return (1);
}

void	choose_opperation(t_opp *op)
{
	int	ce;

	ce = 0;
	if (is_sorted_a(op) == 1)
	{
		ce = list_lenght(op, 1);
		if (ce <= 3)
			swap_three(op);
		else if (ce <= 5 && ce > 3)
			swap_five(op);
		//else
		//	sort_big_stack(op); // wird in einem
	}
	ft_printf("list lenght: %d\n", list_lenght(op, 1));
}
