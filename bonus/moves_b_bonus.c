/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_b_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-ouaz <yel-ouaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 14:46:54 by yel-ouaz          #+#    #+#             */
/*   Updated: 2024/08/03 17:01:46 by yel-ouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sb(t_node **head)
{
	t_node	*third;

	if (!head || !(*head) || !((*head)->next))
		return ;
	third = (*head)->next->next;
	(*head)->next->next = *head;
	(*head) = (*head)->next;
	(*head)->next->next = third;
}

void	pb(t_node **stack_a, t_node **stack_b)
{
	t_node	*node;

	if (!stack_a || !(*stack_a) || !stack_b)
		return ;
	node = *stack_a;
	*stack_a = (*stack_a)->next;
	node->next = *stack_b;
	*stack_b = node;
}

void	rb(t_node **head)
{
	t_node	*i;

	if (!head || !(*head) || !((*head)->next))
		return ;
	i = *head;
	while (i->next)
		i = i->next;
	i->next = *head;
	*head = (*head)->next;
	i->next->next = NULL;
}

void	rrb(t_node **head)
{
	t_node	*last;
	t_node	*i;

	if (!head || !(*head) || !((*head)->next))
		return ;
	i = *head;
	while (i->next->next)
		i = i->next;
	last = i ->next;
	i->next = NULL;
	last->next = *head;
	*head = last;
}
