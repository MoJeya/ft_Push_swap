/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:35:03 by mjeyavat          #+#    #+#             */
/*   Updated: 2022/01/13 18:29:06 by mjeyavat         ###   ########.fr       */
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

int	check_str_input(char *str)
{
	int	str_len;
	int	i;

	str_len = ft_strlen(str);
	i = 0;
	if (str == NULL)
		return (0);
	while (*str)
	{
		if (*str == ' ')
			i++;
		str++;
	}
	if (i == str_len)
		return (0);
	return (1);
}

// void	ft_print_list(t_opp *opp)
// {
// 	t_node			*tmp_a;
// 	t_node			*tmp_b;

// 	tmp_a = opp->stack_a;
// 	tmp_b = opp->stack_b;
// 	ft_printf("A:	 B:\n");
// 	while (tmp_a != NULL || tmp_b != NULL)
// 	{
// 		if (tmp_a)
// 		{
// 			ft_printf("[%d][%d]", tmp_a->rank, tmp_a->data);
// 			tmp_a = tmp_a->next;
// 		}
// 		ft_printf("	");
// 		if (tmp_b)
// 		{
// 			ft_printf("[%d][%d]", tmp_b->rank, tmp_b->data);
// 			tmp_b = tmp_b->next;
// 		}
// 		ft_printf("\n");
// 	}
// }

long	ft_l_atoi(const char *str)
{
	long	i;
	long	result;
	long	negativ;

	result = 0;
	negativ = 1;
	i = 0;
	while (((str[i] >= 9) && (str[i] <= 13)) || (str[i] == 32))
		i++;
	if (str[i] == '-')
	{
		negativ = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if (result == 2147483647)
			break ;
		i++;
	}
	return (result * negativ);
}

int	get_char(char *str)
{
	int		i;
	long	tmp_num;
	char	*tmp;

	i = 1;
	tmp_num = 0;
	tmp = str;
	tmp_num = ft_l_atoi(tmp);
	if (tmp_num < -2147483648 || tmp_num > 2147483647)
		i = 0;
	if (*tmp == '-')
		tmp++;
	if (!ft_isdigit(*tmp))
		i = 0;
	while (*tmp)
	{
		if (ft_isdigit((*tmp)) != 1)
			i = 0;
		tmp++;
	}
	return (i);
}

int	data_on_pos(t_opp *op, int pos, int option)
{
	int		data;
	t_node	*tmp;

	data = 0;
	tmp = NULL;
	if (option == 1)
		tmp = op->stack_a;
	else if (option == 2)
		tmp = op->stack_b;
	if (pos == 0)
		return (tmp->data);
	while (pos > 0 && tmp->next != NULL)
	{
		tmp = tmp->next;
		data = tmp->data;
		pos--;
	}
	if (pos < 0)
		return (tmp->data);
	return (data);
}
