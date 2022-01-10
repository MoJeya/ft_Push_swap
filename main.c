/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:09:18 by mjeyavat          #+#    #+#             */
/*   Updated: 2022/01/10 15:05:07 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

/*
	TODO:
		the user input with on stirng has to be reworked
		//////(Mohan) finsih Operations rr and rrr
		////(Mohan) Opperation's coner cases has to be done
		////(Mohan) list init fucntion fixen!
		////	(info)liste wird nicht richtig inizalieseirt
		////(MOHAN) Fix Convert String Function!
		////(MOHAN) build Opperotattion with linked list
		/////(Mohan) Learn about linked lilst (again) for maximum effecity
*/

static void	creat_lst(int argc, char *argv[], t_node **head)
{
	t_node	*tmp;
	int		j;

	j = argc - 1;
	while (j >= 1)
	{
		if (get_char(argv[j]) == 0)
		{
			tmp = create_node(ft_atoi(argv[j]), 0);
			tmp->next = *head;
			*head = tmp;
		}
		else
		{
			ft_printf("Error\n");
			exit(1);
		}
		j--;
	}
}

t_node	*convert_str_lst(const char *str, t_node	**head)
{
	char	**tmp;
	t_node	*lst;

	tmp = ft_split(str, ' ');
	while (*tmp != NULL)
	{
		if (get_char(*tmp) != 0)
		{
			lst = create_node(ft_atoi(*tmp), 0);
			lst->next = *head;
			*head = lst;
		}
		else
		{
			ft_printf("Error\n");
			exit(1);
		}
		free (*tmp);
		tmp++;
	}
	revers_lst(head);
	return ((*head));
}
/**
 * look at the first value in current and compare
 * it to every value in the list, throug iteration
 *
*/

void	set_rank(t_node **stack_a, t_node *current)
{
	t_node	*compare_to;

	compare_to = *stack_a;
	while (compare_to)
	{
		if (current->data > compare_to->data)
			current->rank++;
		compare_to = compare_to->next;
	}
}

void	set_rankloop(t_node *stack_a)
{
	t_node	*current;

	current = stack_a;
	while (current)
	{
		set_rank(&stack_a, current);
		current = current->next;
	}
}

int	main(int argc, char *argv[])
{
	t_opp	*opps;

	opps = (t_opp *)malloc(sizeof(t_opp));
	opps->stack_a = NULL;
	opps->stack_b = NULL;
	if (argc == 2)
	{
		convert_str_lst(argv[1], &opps->stack_a);
	}
	else if (argc >= 3)
	{
		creat_lst(argc, argv, &opps->stack_a);
	}
	else
		ft_printf("argument invalid!\n");
	set_rankloop(opps->stack_a);
	choose_opperation(opps);
	//ft_print_list(opps);
	//system("leaks push_swap");
	return (0);
}
