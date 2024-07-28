/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-ouaz <yel-ouaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 23:09:15 by yel-ouaz          #+#    #+#             */
/*   Updated: 2024/07/27 20:00:03 by yel-ouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	top_ra(t_node **head_a, t_node **head_b, int position, int flag)
{
	while (position > 1)
	{
		if (flag == 1)
		{
			rr(head_a, head_b);
			flag = 0;
			position--;
		}
		ra(head_a);
		position--;
	}
}

void	top_rra(t_node **head_a, t_node **head_b, int position, int flag)
{
	int	size;

	size = lst_size(*head_a);
	while (position < size + 1)
	{
		if (flag == 1)
		{
			rb(head_b);
			flag = 0;
		}
		rra(head_a);
		position++;
	}
}

void	top_a(t_node **head_a, t_node **head_b, int position, int flag)
{
	int	size;

	size = lst_size(*head_a);
	if (position == 1)
	{
		if (flag == 1)
			rb(head_b);
		return ;
	}
	if (position == 2)
	{
		if (flag == 1)
			rb(head_b);
		sa(head_a);
		return ;
	}
	if (position <= (size / 2))
		top_ra(head_a, head_b, position, flag);
	else
		top_rra(head_a, head_b, position, flag);
}

void	top_b(t_node **head, int position)
{
	int	size;

	size = lst_size(*head);
	if (position == 1)
		return ;
	if (position == 2)
		return (sb(head));
	if (position <= (size / 2))
	{
		while (position > 1)
		{
			rb(head);
			position--;
		}
	}
	else
	{
		while (position < size + 1)
		{
			rrb(head);
			position++;
		}
	}
}

void	the_rest(t_node **head_a, t_node **head_b)
{
	int	chunk;
	int	i;

	set_chunk(lst_size(*head_a), &chunk, &i);
	push_chunks(head_a, head_b, chunk, i);
	push_back(head_a, head_b);
}
