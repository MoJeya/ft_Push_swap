/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:09:18 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/11/24 14:40:41 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

/*
	TODO:
		(Mohan) list init fucntion fixen!
!			(info)liste wird nicht richtig inizalieseirt
		////(MOHAN) Fix Convert String Function!
		////(MOHAN) build Opperation with linked list
		(Mohan) Learn about linked lilst (again) for maximum effecity
*/

static void	creat_lst(int argc, char *argv[], t_node **head, int flag)
{
	t_node	*tmp;
	int		j;

	j = argc - 1;
	while (j >= 1)
	{
		if (flag == 1)
			tmp = create_node(ft_atoi(argv[j]));
		else
			tmp = create_node(0);
		tmp->next = *head;
		*head = tmp;
		j--;
	}
}

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;


	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1)
	{
		ft_printf("Pleas enter the Numbers!\n");
		return (1);
	}
	else if (argc > 3)
	{
		creat_lst(argc, argv, &stack_a, 1);
		creat_lst(argc, argv, &stack_b, 0);
		//ft_print_list(stack_a);
	}
	else if (argc == 2)
	{
		ft_printf("The argument will be worked with!\n");
		set_arr(argv, argc, &stack_a, 1);
		set_arr(argv, argc, &stack_b, 0);
	}
	//ft_pb(stack_a, stack_b);
	//free(stack_a);
	ft_print_list(stack_a, stack_b);
	return (0);
}
