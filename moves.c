/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-ouaz <yel-ouaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 23:15:40 by yel-ouaz          #+#    #+#             */
/*   Updated: 2024/07/13 21:38:39 by yel-ouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(t_node **head)
{
	t_node *third;
	
	if (!head || !((*head)->next))
		return ;
	third = (*head)->next->next;
	(*head)->next->next = *head;
	(*head) = (*head)->next;
	(*head)->next->next = third;
	write(1, "sa\n", 3);
}

void sb(t_node **head)
{
	t_node *third;
	
	if (!head || !((*head)->next))
		return ;
	third = (*head)->next->next;
	(*head)->next->next = *head;
	(*head) = (*head)->next;
	(*head)->next->next = third;
	write(1, "sb\n", 3);
}

void ss(t_node **stack_a, t_node **stack_b)
{
	t_node *third;
	
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
	write(1,"ss\n",3);
}

void pa(t_node **stack_a, t_node **stack_b)
{
	t_node *node;

	if (!stack_b || !(*stack_b) || !stack_a)
		return ;
	node = *stack_b;
	*stack_b = (*stack_b)->next;
	node->next = *stack_a;
	*stack_a = node;
	write(1, "pa\n", 3);
}

void pb(t_node **stack_a, t_node **stack_b)
{
	t_node *node;

	if (!stack_a || !(*stack_a) || !stack_b)
		return ;
	node = *stack_a;
	*stack_a = (*stack_a)->next;
	node->next = *stack_b;
	*stack_b = node;
	write(1, "pb\n",3);
}

void ra(t_node **head)
{
	t_node	*i;

	if (!head || !(*head) || !((*head)->next))
		return ;
	i = *head;
	while(i->next)
		i = i->next;
	i->next = *head;
	*head= (*head)->next;
	i->next->next = NULL;
	write(1, "ra\n", 3);
}

void rb(t_node **head)
{
	t_node	*i;

	if (!head || !(*head) || !((*head)->next))
		return ;
	i = *head;
	while(i->next)
		i = i->next;
	i->next = *head;
	*head= (*head)->next;
	i->next->next = NULL;
	write(1, "rb\n", 3);
}

void	rr(t_node **head_a, t_node **head_b)
{
	t_node	*i;

	i = 0;
	if (head_a && *head_a && (*head_a)->next)
	{
		i = *head_a;
		while(i->next)
			i = i->next;
		i->next = *head_a;
		*head_a= (*head_a)->next;
		i->next->next = NULL;
	}
	if (head_b && *head_b && (*head_b)->next)
	{
		i = *head_b;
		while(i->next)
			i = i->next;
		i->next = *head_b;
		*head_b= (*head_b)->next;
		i->next->next = NULL;
	}
	if (i)
		write(1, "rr\n", 3);
}

void	rra(t_node **head)
{
	t_node *i;
	t_node *last;

	if (!head || !(*head) || !((*head)->next))
		return ;
	i = *head;
	while(i->next->next)
		i = i->next;
	last = i ->next;
	i->next = NULL;
	last->next = *head;
	*head = last;
	write(1, "rra\n", 4);
}

void	rrb(t_node **head)
{
	t_node *i;
	t_node *last;

	if (!head || !(*head) || !((*head)->next))
		return ;
	i = *head;
	while(i->next->next)
		i = i->next;
	last = i ->next;
	i->next = NULL;
	last->next = *head;
	*head = last;	
	write(1, "rrb\n", 4);
}

void	rrr(t_node **head_a, t_node **head_b)
{
	t_node *i;
	t_node *last;
	
	i = 0;
	if (head_a && *head_a && (*head_a)->next)
	{
		i = *head_a;
		while(i->next->next)
			i = i->next;
		last = i ->next;
		i->next = NULL;
		last->next = *head_a;
		*head_a = last;	
	}
	if (head_b && *head_b && (*head_b)->next)
	{
		i = *head_b;
		while(i->next->next)
			i = i->next;
		last = i ->next;
		i->next = NULL;
		last->next = *head_b;
		*head_b = last;	
	}
	(i) && (write(1, "rrr\n", 4));
}
