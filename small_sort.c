/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-ouaz <yel-ouaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 14:26:53 by yel-ouaz          #+#    #+#             */
/*   Updated: 2024/07/27 14:28:55 by yel-ouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_node **head_a)
{
	if ((*head_a)->content > (*head_a)->next->content)
		sa(head_a);
}

void	sort_three(t_node **head_a)
{
	int	max;

	max = get_max(*head_a);
	if (max == 2)
		rra(head_a);
	if (max == 1)
		ra(head_a);
	if ((*head_a)->content > (*head_a)->next->content)
		sa(head_a);
}

void	sort_four(t_node **head_a, t_node **head_b)
{
	top_a(head_a, head_b, get_min(*head_a), 0);
	if (sorted(*head_a))
		return ;
	pb(head_a, head_b);
	sort_three(head_a);
	pa(head_a, head_b);
}

void	sort_five(t_node **head_a, t_node **head_b)
{
	top_a(head_a, head_b, get_min(*head_a), 0);
	if (sorted(*head_a))
		return ;
	pb(head_a, head_b);
	sort_four(head_a, head_b);
	pa(head_a, head_b);
}

void	small_sort(int size, t_node **head_a, t_node **head_b)
{
	if (size == 2)
		sort_two(head_a);
	if (size == 3)
		sort_three(head_a);
	if (size == 4)
		sort_four(head_a, head_b);
	if (size == 5)
		sort_five(head_a, head_b);
}
