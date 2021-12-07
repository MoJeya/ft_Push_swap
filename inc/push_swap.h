/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:55:51 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/12/07 20:11:04 by mjeyavat         ###   ########.fr       */
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
void	ft_sa(t_opp *opp);
void	ft_sb(t_opp *opp);
void	ft_rot(t_node **stack);
void	ft_revrot(t_node **stack);
void	ft_rr(t_opp *opp);
void	ft_ss(t_opp *opp);
void	ft_pb(t_opp *opp);
void	ft_pa(t_opp *opp);
t_node	*create_node(int num);
void	revers_lst(t_node **head);
int		get_char(char *str);
int		list_lenght(t_opp *op, int stack_option);
int		max_n(t_opp *op);
int		min_n(t_opp *op);
void	swap_three(t_opp *op);
int		lst_find_pos(t_opp *op, int val);
int		ft_findmin_val(t_opp *op, int val);
int		ft_findrmin_val(t_node *stack, int val);
int		get_data_on_pos(t_opp *op, int pos);
int		comp_data(t_opp *op, int minval_pos1, int minval_pos2);
void	set_top_b(t_node **stack, int pos, int mid_val);

#endif
