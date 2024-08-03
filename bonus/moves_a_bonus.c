/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_a_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-ouaz <yel-ouaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 23:15:40 by yel-ouaz          #+#    #+#             */
/*   Updated: 2024/08/03 17:01:34 by yel-ouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	sa(t_node **head)
{
	t_node	*third;

	if (!head || !(*head) || !((*head)->next))
		return ;
	third = (*head)->next->next;
	(*head)->next->next = *head;
	(*head) = (*head)->next;
	(*head)->next->next = third;
}

void	pa(t_node **stack_a, t_node **stack_b)
{
	t_node	*node;

	if (!stack_b || !(*stack_b) || !stack_a)
		return ;
	node = *stack_b;
	*stack_b = (*stack_b)->next;
	node->next = *stack_a;
	*stack_a = node;
}

void	ra(t_node **head)
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

void	rra(t_node **head)
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
