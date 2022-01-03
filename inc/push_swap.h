/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:55:51 by mjeyavat          #+#    #+#             */
/*   Updated: 2022/01/03 12:32:58 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"

typedef struct Node
{
	int			data;
	struct Node	*next;
}	t_node;

typedef struct s_opp
{
	t_node	*stack_a;
	t_node	*stack_b;
}	t_opp;

void	check_which_op(t_opp *op);
void	ft_print_list(t_opp *opp);
int		sa(t_opp *opp);
int		sb(t_opp *opp);
int		ft_rot(t_node **stack);
int		ft_revrot(t_node **stack);
int		ft_rr(t_opp *opp);
int		ss(t_opp *opp);
int		pb(t_opp *opp);
int		pa(t_opp *opp);
t_node	*create_node(int num);
void	revers_lst(t_node **head);
int		get_char(char *str);
int		list_lenght(t_opp *op, int stack_option);
int		max_n(t_opp *op, int option);
int		min_n(t_opp *op);
void	swap_three(t_opp *op);
int		lst_find_pos(t_opp *op, int val, int option);
int		ft_findmin_val(t_opp *op, int val);
int		data_on_pos(t_opp *op, int pos, int option);
int		is_num_lst(t_opp *op, int num);
//int		lst_find_pos(t_opp *op, int val, int option);
int		find_num(int chunck_x, t_opp *op, int *addi);
void	pick_set(int *chunk_x, int *end, int list_len);
int		push_back_a(t_opp *op);
void	pick_set_500(int *chunk_x, int *end, int list_len);
int		find_num_ver2(int chunck_x, t_opp *op, int *addi, int list_len);

#endif
