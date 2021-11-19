/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:09:18 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/11/19 12:51:37 by mjeyavat         ###   ########.fr       */
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

static void	init_listab(t_node *sa, t_node *sb, int argc, char *argv[])
{
	int		i;
	int		tmp_num;

	ft_printf("Stacks initzialisation is done!\nStack A:			Satck B:\n");
	i = 1;
	while (i < argc)
	{
		tmp_num = ft_atoi(argv[i]);
		init_list_a(sa, tmp_num);
		inti_list_b(sb);
		ft_printf("[%d]				[%d]\n", sa->data, sb->data);
		i++;
	}
}

static void	ft_convert_str(const char *str, t_node *st_a, t_node *st_b)
{
	int				cnt;
	char			**tmp;

	cnt = 0;
	tmp = ft_split(str, ' ');
	ft_printf("Stacks initzialisation is done!\nStack A:			Satck B:\n");
	while (tmp[cnt] != NULL)
	{
		init_list_a(st_a, ft_atoi(tmp[cnt]));
		inti_list_b(st_b);
		ft_printf("[%d]				[%d]\n", st_a->data, st_b->data);
		cnt++;
	}
	free(tmp);
}

int	main(int argc, char *argv[])
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		i;
	int		tmp_num;

	stack_a = NULL;
	stack_b = NULL;
	stack_a = (t_node *)malloc(sizeof(t_node));
	stack_b = (t_node *)malloc(sizeof(t_node));
	if (!stack_a || !stack_b)
		return (0);
	if (argc == 1)
	{
		ft_printf("Pleas enter the Numbers!\n");
		return (1);
	}
	else if (argc > 3)
		init_listab(stack_a, stack_b, argc, argv);
	else if (argc == 2)
	{
		ft_printf("The argument will be worked with!\n");
		ft_convert_str(argv[1], stack_a, stack_b);
	}
	ft_pb(stack_a, stack_b);
	ft_print_list(stack_a, stack_b);
	return (0);
}
