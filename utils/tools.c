/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:35:03 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/11/25 20:22:53 by mjeyavat         ###   ########.fr       */
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
	ft_printf("Stack A:			stack B:\n");
	while (tmp_a != NULL || tmp_b != NULL)
	{
		if (tmp_a)
		{
			ft_printf("[%d]", tmp_a->data);
			tmp_a = tmp_a->next;
		}
		ft_printf("				");
		if (tmp_b)
		{
			ft_printf("[%d]", tmp_b->data);
			tmp_b = tmp_b->next;
		}
		ft_printf("\n");
		//else
		//	ft_printf("[%d]			[%d]\n", tmp_a->data, tmp_b->data);
	}
}

//void	convert_str_lst(char *argv[], t_node **head)
//{
//	int		i;
//	char	**tmp;
//	t_node	*new;

//	i = 0;
//	tmp = ft_split(argv[1], ' ');
//	while (tmp[i] != NULL)
//		i++;
//	while (i - 1 >= 0)
//	{
//			new = create_node(ft_atoi(tmp[i - 1]));
//		new->next = *head;
//		*head = new;
//		i--;
//	}
//	ft_printf("\n");
//}

/*
 * This function should initzialase nodes on
	a list
*/
