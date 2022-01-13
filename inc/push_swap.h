/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:55:51 by mjeyavat          #+#    #+#             */
/*   Updated: 2022/01/13 18:31:25 by mjeyavat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf/ft_printf.h"

typedef struct Node
{
	int			data;
	struct Node	*next;
	int			rank;
}	t_node;

typedef struct s_opp
{
	t_node	*stack_a;
	t_node	*stack_b;
}	t_opp;

void	ft_print_list(t_opp *opp);
int		sa(t_node *stack_a);
int		sb(t_node *stack_b);
int		rra(t_node **stack_a);
int		ra(t_node **stack_a);
int		rb(t_node **stack_b);
int		rr(t_opp *opp);
int		ss(t_opp *opp);
int		pb(t_opp *opp);
int		pa(t_opp *opp);
void	put_stack_back(t_opp *op);
t_node	*rotat_stack_down(t_node **stack);
t_node	*rotat_stack_up(t_node **stack);
t_node	*create_node(int num, int rank);
void	revers_lst(t_node **head);
int		get_char(char *str);
int		list_lenght(t_opp *op, int stack_option);
int		max_n(t_opp *op, int option);
int		min_n(t_opp *op);
void	swap_three(t_opp *op);
void	swap_five(t_opp *op);
int		lst_find_pos(t_opp *op, int val, int option);
void	choose_opperation(t_opp *op);
int		sort_big_stack(t_opp *op, int list_len);
int		is_sorted_a(t_opp *op);
int		check_dup(t_opp *op);
long	ft_l_atoi(const char *str);
void	pick_set(int *chunk_x, int *end, int list_len);
//int		push_back_a(t_opp *op);
void	free_ar(char **str);
int		check_str_input(char *str);
void	create_list(char *str, t_node **head, t_node *lst);
void	error_ex(void);
#endif
