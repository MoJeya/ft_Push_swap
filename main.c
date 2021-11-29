/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:09:18 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/11/29 14:19:36 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

/*
	TODO:
		(Mohan) Opperation's coner cases has to be done
		!(Mohan) finsih Operations rr and rrr
		////(Mohan) list init fucntion fixen!
		////	(info)liste wird nicht richtig inizalieseirt
		////(MOHAN) Fix Convert String Function!
		////(MOHAN) build Opperotattion with linked list
		(Mohan) Learn about linked lilst (again) for maximum effecity
*/

static void	creat_lst(int argc, char *argv[], t_node **head)
{
	t_node	*tmp;
	int		j;

	j = argc - 1;
	while (j >= 1)
	{
		tmp = create_node(ft_atoi(argv[j]));
		tmp->next = *head;
		*head = tmp;
		j--;
	}
}

int	main(int argc, char *argv[])
{
	t_opp	*opps;

	opps = (t_opp *)malloc(sizeof(t_opp));
	opps->stack_a = NULL;
	opps->stack_b = NULL;
	if (argc == 1)
	{
		ft_printf("Pleas enter the Numbers!\n");
		return (1);
	}
	else if (argc > 3)
	{
		creat_lst(argc, argv, &opps->stack_a);
		//opps->op = " ";
	}
	ft_print_list(opps);
	ft_ss(opps);
	ft_pb(opps);
	ft_pb(opps);
	ft_print_list(opps);
	ft_rr(&opps->stack_a);
	ft_print_list(opps);
	system("leaks push_swap");
	return (0);
}
