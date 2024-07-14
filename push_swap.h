/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-ouaz <yel-ouaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 22:12:10 by yel-ouaz          #+#    #+#             */
/*   Updated: 2024/07/13 04:38:37 by yel-ouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

#include <stdio.h>


typedef struct s_node t_node;

struct s_node
{
	int		content;
	int		index;
	t_node	*next;
};

int		check_args(int argc, char **args);
void	make_list(int argc, char **argv, t_node **head);
char	**ft_split(char *s, char c);
char	**ft_freearray(char **s, int i);
void	free_list(t_node *head);
void	check_list(t_node *head);
void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
void	ss(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);
void	pa(t_node **stack_a, t_node **stack_b);
void	ra(t_node **head);
void	rb(t_node **head);
void	rr(t_node **head_a, t_node **head_b);
void	rra(t_node **head);
void	rrb(t_node **head);
void	rrr(t_node **head_a, t_node **head_b);

#endif