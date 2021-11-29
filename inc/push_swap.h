/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:55:51 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/11/29 14:12:35 by mjeyavat         ###   ########.fr       */
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

void	ft_print_list(t_opp *opp);
void	convert_str_lst(char *argv[], t_node **head);
void	ft_sa(t_opp *opp);
void	ft_sb(t_opp *opp);
void	ft_ro(t_node **stack);
void	ft_rr(t_node **stack);
void	ft_ss(t_opp *opp);
void	ft_pb(t_opp *opp);
void	ft_pa(t_opp *opp);

t_node	*create_node(int num);

#endif
