/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 16:09:18 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/11/18 18:45:04 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/push_swap.h"

/*
	TODO:
		(MOHAN) Fix Convert String Function!
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

static int	ft_convert_str(const char *str, t_node *sa, t_node *sb)
{
	int				wc;
	int				cnt;
	char			**tmp;
	int				tmp_num;

	wc = 0;
	cnt = 0;
	*tmp = *ft_split(str, ' ');
	wc = ft_strlen(*tmp);
	while (wc != 0)
	{
		printf("tmp: %s\n", *tmp);
		tmp_num = ft_atoi(tmp[cnt]);
		init_list_a(sa, tmp_num);
		inti_list_b(sb);
		cnt++;
		wc--;
	}
	//free(tmp);
	return (0);
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
	else if (argc > 1)
		init_listab(stack_a, stack_b, argc, argv);
	else if (argc == 2)
		ft_convert_str(argv[1], stack_a, stack_b);
	return (0);
}
