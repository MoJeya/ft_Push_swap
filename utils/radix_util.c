/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 18:02:23 by mjeyavat          #+#    #+#             */
/*   Updated: 2022/01/13 18:33:38 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	error_ex(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

void	create_list(char *str, t_node **head, t_node *lst)
{
	lst = create_node(ft_atoi(str), 0);
	lst->next = *head;
	*head = lst;
}

static void	shift_loop(t_opp *op, int list_len, int loop_cnt)
{
	int	i;

	i = 0;
	while (i < list_len)
	{
		if ((op->stack_a->rank >> loop_cnt) & 1)
			ra(&op->stack_a);
		else
			pb(op);
		i++;
	}
}

static void	radix_sort(t_opp *op, int list_len)
{
	int	loop_cnt;
	int	max_num;
	int	max_bit;

	loop_cnt = 0;
	max_num = list_len - 1;
	max_bit = 0;
	while ((max_num >> max_bit) != 0)
		max_bit++;
	while (loop_cnt <= max_bit)
	{
		shift_loop(op, list_len, loop_cnt);
		put_stack_back(op);
		if (is_sorted_a(op) == 0)
			break ;
		loop_cnt++;
	}
}

int	sort_big_stack(t_opp *op, int list_len)
{
	radix_sort(op, list_len);
	return (0);
}
