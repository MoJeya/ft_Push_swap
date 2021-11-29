/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:35:03 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/11/29 15:44:00 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_node	*create_node(int num)
{
	t_node	*tmp;

	tmp = (t_node *)malloc(sizeof(t_node));
	tmp->data = num;
	tmp->next = NULL;
	return (tmp);
}

void	ft_print_list(t_opp *opp)
{
	t_node			*tmp_a;
	t_node			*tmp_b;

	tmp_a = opp->stack_a;
	tmp_b = opp->stack_b;
	ft_printf("A:	 B:\n");
	while (tmp_a != NULL || tmp_b != NULL)
	{
		if (tmp_a)
		{
			ft_printf("[%d]", tmp_a->data);
			tmp_a = tmp_a->next;
		}
		ft_printf("	");
		if (tmp_b)
		{
			ft_printf("[%d]", tmp_b->data);
			tmp_b = tmp_b->next;
		}
		ft_printf("\n");
	}
}
