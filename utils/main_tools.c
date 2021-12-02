/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:35:03 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/12/02 18:11:16 by mjeyavat         ###   ########.fr       */
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

t_node	*get_lstlast(t_node **node)
{
	t_node	 *current;

	current = create_node((*node)->data);
	current->next = (*node);
	(*node) = current;
	return ((*node));
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

int	get_char(char *str)
{
	int	i;

	i = 0;
	while (ft_isdigit(str[i]) == 1)
		i++;
	return (i);
}
