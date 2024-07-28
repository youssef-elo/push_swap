/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_joint_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-ouaz <yel-ouaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 14:47:14 by yel-ouaz          #+#    #+#             */
/*   Updated: 2024/07/28 17:21:01 by yel-ouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ss(t_node **stack_a, t_node **stack_b)
{
	t_node	*third;

	if (stack_a && *stack_a && ((*stack_a)->next))
	{
		third = (*stack_a)->next->next;
		(*stack_a)->next->next = *stack_a;
		(*stack_a) = (*stack_a)->next;
		(*stack_a)->next->next = third;
	}
	if (stack_b && *stack_b && ((*stack_b)->next))
	{
		third = (*stack_b)->next->next;
		(*stack_b)->next->next = *stack_b;
		(*stack_b) = (*stack_b)->next;
		(*stack_b)->next->next = third;
	}
}

void	rr(t_node **head_a, t_node **head_b)
{
	t_node	*i;

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
}

void	rrr(t_node **head_a, t_node **head_b)
{
	t_node	*last;
	t_node	*i;

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
}
