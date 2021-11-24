/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:35:03 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/11/24 14:40:42 by mjeyavat         ###   ########.fr       */
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

void	ft_print_list(t_node *st_a, t_node *st_b)
{
	t_node			*tmp_a;
	t_node			*tmp_b;

	tmp_a = st_a;
	tmp_b = st_b;
	if (st_a == NULL)
		ft_printf("Unable to initzailise Memory!\n");
	ft_printf("Stack A:					stack B:\n");
	while (tmp_a != NULL)
	{
		ft_printf("[%d]						[%d]\n", tmp_a->data, tmp_b->data);
		tmp_a = tmp_a->next;
		tmp_b = tmp_b->next;
	}
}

void	set_arr(char *argv[], int argc, t_node **head, int flag)
{
	int		i;
	char	**tmp;
	t_node	*new;

	i = 0;
	tmp = ft_split(argv[1], ' ');
	while (tmp[i] != NULL)
	{
		if (flag == 1)
			new = create_node(ft_atoi(tmp[i]));
		else
			new = create_node(0);
		new->next = *head;
		*head = new;
		i++;
	}
	ft_printf("\n");
}

/*
 * This function should initzialase nodes on
	a list
*/
