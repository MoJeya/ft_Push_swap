/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:35:03 by mjeyavat          #+#    #+#             */
/*   Updated: 2022/01/06 13:41:28 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_node	*create_node(int num, int rank)
{
	t_node	*tmp;

	tmp = (t_node *)malloc(sizeof(t_node));
	tmp->data = num;
	tmp->rank = rank;
	tmp->next = NULL;
	return (tmp);
}

void	revers_lst(t_node **head)
{
	t_node	*prv;
	t_node	*curr;
	t_node	*nxt;

	prv = NULL;
	curr = *head;
	nxt = NULL;
	while (curr != NULL)
	{
		nxt = curr->next;
		curr->next = prv;
		prv = curr;
		curr = nxt;
	}
	(*head) = prv;
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
			ft_printf("[%d][%d]", tmp_a->data, tmp_a->rank);
			tmp_a = tmp_a->next;
		}
		ft_printf("	");
		if (tmp_b)
		{
			ft_printf("[%d][%d]", tmp_b->data, tmp_b->rank);
			tmp_b = tmp_b->next;
		}
		ft_printf("\n");
	}
}

int	get_char(char *str)
{
	int	i;

	i = 0;
	if (ft_atoi(str))
		return (i);
	else
		return (1);
}

void	change_range(int *r_start, int *r_end)
{
	(*r_start) = (*r_end);
	(*r_end) += 25;
}
