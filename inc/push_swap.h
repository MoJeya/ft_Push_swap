/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjeyavat <mjeyavat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 15:55:51 by mjeyavat          #+#    #+#             */
/*   Updated: 2021/11/28 18:32:00 by mjeyavat         ###   ########.fr       */
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

void	ft_print_list(t_node *st_a, t_node *st_b);
void	convert_str_lst(char *argv[], t_node **head);
void	ft_sa(t_node **st_a);
void	ft_sb(t_node **st_b);
void	ft_rotat(t_node **stack, char aorb);
void	ft_r_rotat(t_node **stack, char aorb);
void	ft_ss(t_node **st_a, t_node **st_b);
void	ft_pb(t_node **st_a, t_node **st_b);
void	ft_pa(t_node **st_a, t_node **st_b);

t_node	*create_node(int num);

#endif
