/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:02:23 by mjeyavat          #+#    #+#             */
/*   Updated: 2022/01/08 16:49:44 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/**
 * Radix sort will be implemented here
*/

//static int	get_base_len(int num)
//{
//	int	i;

//	i = 0;
//	while (num > 0)
//	{
//		num /= 10;
//		i++;
//	}
//	return (i);
//}

static void	print_bin(int num)
{
	if (num >> 1)
	{
		print_bin(num >> 1);
	} // print the least significant bit and shift it out to the right.
	if (num & 1)
		ft_printf("1");
	else
		ft_printf("0");
}

static int	cycle_throug(int current_val) // code sollte recrusive sein sodass der leszte bit betrachtet werden
{//kann und nicht nur der 2te bit von links also bsp: 0>0<00 > wrong, 000>0< right.
	while (current_val >> 1)
	{
		current_val = current_val >> 1;
		ft_printf("current_val = %d\n", current_val);
	}
	return (current_val);
}
//TODO: these are utilitys for radix sort the actuel function of
// sort_big_stack will be writen somewhere else.
int	sort_big_stack(t_opp *op)
{
	//get right most set bit
	int		current_val;
	t_node	*tmp;

	tmp = op->stack_a;
	current_val = tmp->rank;
	print_bin(current_val);
	ft_printf("\n");
	ft_printf("current value: %d, after cycle %d\n", current_val, cycle_throug(current_val));
	//while (tmp && list_lenght(op, 1))
	//{
	//	if (tmp->next == NULL)
	//		break ;
	//	if (cycle_throug(current_val) & 1)
	//	{
	//		tmp = tmp->next;
	//		//ft_printf("current rank: %d current data: %d\n", tmp->rank, tmp->data);
	//	}
	//	else
	//	{
	//		pb(op);
	//		tmp = tmp->next;
	//	}
	//	current_val = tmp->rank;
	//}

	//if (c & 1)
	//	op->stack_a = op->stack_a->next;
	//else
	//	ft_printf("pb\n");
	//ft_print_list(op);
	return (0);
}
