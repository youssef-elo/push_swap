/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-ouaz <yel-ouaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 22:12:10 by yel-ouaz          #+#    #+#             */
/*   Updated: 2024/07/27 15:49:54 by yel-ouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>

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
int		sorted(t_node *head);
void	sa(t_node **stack_a);
void	sb(t_node **stack_b);
int		get_max(t_node *head);
int		get_min(t_node *head);
int		lst_size(t_node *head);
void	free_arr(char **split);
void	free_list(t_node *head);
void	check_list(t_node *head);
void	sort_two(t_node **head_a);
void	sort_three(t_node **head_a);
char	**ft_split(char *s, char c);
int		get_pos(t_node *head, int in);
int		check_args(int argc, char **args);
void	top_b(t_node **head, int position);
void	ft_exit(char **split, t_node **head);
int		add_node(int content, t_node **head);
void	rr(t_node **head_a, t_node **head_b);
void	rrr(t_node **head_a, t_node **head_b);
void	ss(t_node **stack_a, t_node **stack_b);
void	pb(t_node **stack_a, t_node **stack_b);
void	pa(t_node **stack_a, t_node **stack_b);
void	set_chunk(int size_a, int *chunk, int *i);
void	the_rest(t_node **head_a, t_node **head_b);
void	sort_four(t_node **head_a, t_node **head_b);
void	sort_five(t_node **head_a, t_node **head_b);
void	push_back(t_node **head_a, t_node **head_b);
int		ft_closest(int big, int second, t_node *head);
void	make_list(int argc, char **argv, t_node **head);
void	small_sort(int argc, t_node **head_a, t_node **head_b);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	top_a(t_node **head, t_node **head_b, int position, int flag);
void	push_chunks(t_node **head_a, t_node **head_b, int chunk, int i);

#endif