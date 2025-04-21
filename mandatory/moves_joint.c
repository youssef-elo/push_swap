/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_joint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-ouaz <yel-ouaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 14:47:14 by yel-ouaz          #+#    #+#             */
/*   Updated: 2025/04/21 15:02:03 by yel-ouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ss(t_node **stack_a, t_node **stack_b)
{
	t_node	*third;

	if (stack_a && ((*stack_a)->next))
	{
		third = (*stack_a)->next->next;
		(*stack_a)->next->next = *stack_a;
		(*stack_a) = (*stack_a)->next;
		(*stack_a)->next->next = third;
	}
	if (stack_b && ((*stack_b)->next))
	{
		third = (*stack_b)->next->next;
		(*stack_b)->next->next = *stack_b;
		(*stack_b) = (*stack_b)->next;
		(*stack_b)->next->next = third;
	}
	write(1, "ss\n", 3);
}

void	rr(t_node **head_a, t_node **head_b)
{
	t_node	*i;

	i = 0;
	if (head_a && *head_a && (*head_a)->next)
	{
		i = *head_a;
		while (i->next)
			i = i->next;
		i->next = *head_a;
		*head_a = (*head_a)->next;
		i->next->next = NULL;
	}
	if (head_b && *head_b && (*head_b)->next)
	{
		i = *head_b;
		while (i->next)
			i = i->next;
		i->next = *head_b;
		*head_b = (*head_b)->next;
		i->next->next = NULL;
	}
	if (i)
		write(1, "rr\n", 3);
}

void	rrr(t_node **head_a, t_node **head_b)
{
	t_node	*last;
	t_node	*i;

	i = 0;
	if (head_a && *head_a && (*head_a)->next)
	{
		i = *head_a;
		while (i->next->next)
			i = i->next;
		last = i ->next;
		i->next = NULL;
		last->next = *head_a;
		*head_a = last;
	}
	if (head_b && *head_b && (*head_b)->next)
	{
		i = *head_b;
		while (i->next->next)
			i = i->next;
		last = i ->next;
		i->next = NULL;
		last->next = *head_b;
		*head_b = last;
	}
	if (i)
		write(1, "rrr\n", 4);
}
