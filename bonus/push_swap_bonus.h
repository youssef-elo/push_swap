/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-ouaz <yel-ouaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 20:19:58 by yel-ouaz          #+#    #+#             */
/*   Updated: 2024/07/28 17:20:10 by yel-ouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include "./gnl/get_next_line.h"

typedef struct s_node	t_node;

struct s_node
{
	int		content;
	int		index;
	t_node	*next;
};

void	ra(t_node **head);
void	rb(t_node **head);
void	rra(t_node **head);
void	rrb(t_node **head);
long	ft_atoi(char *str);
void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
int		sorted(t_node *head);
void	free_arr(char **split);
void	free_list(t_node *head);
void	free_list(t_node *head);
void	check_list(t_node *head);
char	**ft_split(char *s, char c);
int		check_args(int argc, char **args);
void	ft_exit(char **split, t_node **head);
int		add_node(int content, t_node **head);
void	rr(t_node **head_a, t_node **head_b);
void	rrr(t_node **head_a, t_node **head_b);
void	ss(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);
void	pa(t_node **stack_a, t_node **stack_b);
int		exec_command(t_node **head_a, t_node **head_b);
void	make_list(int argc, char **argv, t_node **head);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif