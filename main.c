/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:09:18 by mjeyavat          #+#    #+#             */
/*   Updated: 2022/01/12 22:28:01 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

/*
	TODO: every thing works, now get wallgrind working and find the leaks!
		//double numbers has to be handleld
		//the user input with on stirng has to be reworked
		//////(Mohan) finsih Operations rr and rrr
		////(Mohan) Opperation's coner cases has to be done
		////(Mohan) list init fucntion fixen!
		////	(info)liste wird nicht richtig inizalieseirt
		////(MOHAN) Fix Convert String Function!
		////(MOHAN) build Opperotattion with linked list
		/////(Mohan) Learn about linked lilst (again) for maximum effecity
*/

int	check_dup(t_opp *op)
{
	t_node	*head;
	t_node	*cmp_to;
	int		flag;

	head = op->stack_a;
	flag = 0;
	while (head->next != NULL)
	{
		cmp_to = head->next;
		while (cmp_to->next != NULL)
		{
			if (head->data == cmp_to->data)
				flag++;
			cmp_to = cmp_to->next;
		}
		if (head->data == cmp_to->data)
			flag++;
		head = head->next;
	}
	if (flag > 0)
		write(2, "Error\n", 6);
	return (flag);
}

void	convert_str_lst(char *argv[], t_node **head)
{
	char	**tmp;
	t_node	*lst;
	int		i;

	i = 1;
	if (check_str_input(argv[i]) == 0)
		error_exit();
	while (argv[i])
	{
		tmp = ft_split(argv[i], ' ');
		while (*tmp != NULL)
		{
			if (get_char(*tmp) == 1)
			{
				lst = create_node(ft_atoi(*tmp), 0);
				lst->next = *head;
				*head = lst;
			}
			else
				error_exit();
			tmp++;
		}
		i++;
	}
	revers_lst(head);
}

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
	if (argc >= 2)
		convert_str_lst(argv, &opps->stack_a);
	else if (argc == 1)
		exit(EXIT_SUCCESS);
	else
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	set_rankloop(opps->stack_a);
	choose_opperation(opps);
	//system("leaks push_swap");
	return (0);
}
