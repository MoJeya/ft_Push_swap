/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:36:35 by mjeyavat          #+#    #+#             */
/*   Updated: 2022/01/08 13:53:42 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	rra(t_node **stack_a)
{
	rotat_stack_down(stack_a);
	write(1, "rra\n", 4);
	return (1);
}

int	ra(t_node **stack_a)
{
	rotat_stack_up(stack_a);
	write(1, "ra\n", 3);
	return (1);
}

int	rb(t_node **stack_b)
{
	rotat_stack_up(stack_b);
	write(1, "rb\n", 3);
	return (1);
}

int	rr(t_opp *opp)
{
	ra(&opp->stack_a);
	rb(&opp->stack_b);
	write(1, "rr\n", 3);
	return (1);
}

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
