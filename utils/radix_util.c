/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:02:23 by mjeyavat          #+#    #+#             */
/*   Updated: 2022/01/10 18:03:51 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

/**
 * Radix sort will be implemented here
*/
// static void	sort_fourth_bit(t_opp *op, int list_len)
// {
// 	int	loop_cnt;
// 	int	fourth_bit;

// 	loop_cnt = 0;
// 	fourth_bit = 0;
// 	while (loop_cnt <= (list_len * 2))
// 	{
// 		fourth_bit = (op->stack_a->rank >> 3);
// 		if (fourth_bit & 1)
// 			ra(&op->stack_a);
// 		else
// 			pb(op);
// 		loop_cnt++;
// 	}
// 	put_stack_back(op);
// }

// static void	sort_third_bit(t_opp *op, int list_len)
// {
// 	int	loop_cnt;
// 	int	third_bit;

// 	loop_cnt = 0;
// 	third_bit = 0;
// 	while (loop_cnt <= (list_len * 2))
// 	{
// 		third_bit = (op->stack_a->rank >> 2);
// 		if (third_bit & 1)
// 			ra(&op->stack_a);
// 		else
// 			pb(op);
// 		loop_cnt++;
// 	}
// 	put_stack_back(op);
// }

// static void	sort_second_bit(t_opp *op, int list_len)
// {
// 	int		loop_cnt;
// 	int		second_bit;

// 	loop_cnt = 0;
// 	second_bit = 0;
// 	while (loop_cnt <= (list_len * 2))
// 	{
// 		second_bit = (op->stack_a->rank >> 1);
// 		if (second_bit & 1)
// 			ra(&op->stack_a);
// 		else
// 			pb(op);
// 		loop_cnt++;
// 	}
// 	put_stack_back(op);
// }

static void	sort_first_bit(t_opp *op, int list_len)
{
	int	loop_cnt;
	int	max_num;
	int	max_bit;
	int	i;

	loop_cnt = 0;
	max_num = list_len - 1;
	max_bit = 0;
	i = 0;
	while ((max_num >> max_bit) != 0)
		max_bit++;
	while (loop_cnt <= max_bit)
	{
		while (i < list_len)
		{
			if ((op->stack_a->rank >> loop_cnt) & 1)
				ra(&op->stack_a);
			else
				pb(op);
			i++;
		}
		put_stack_back(op);
		if (is_sorted_a(op) == 0)
			break ;
		i = 0;
		loop_cnt++;
	}
}
//TODO: these are utilitys for radix sort the actuel function of
// sort_big_stack will be writen somewhere else, if there are to many funtions
int	sort_big_stack(t_opp *op, int list_len)
{
	sort_first_bit(op, list_len);
	return (0);
}
