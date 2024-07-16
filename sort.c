/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-ouaz <yel-ouaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 23:09:15 by yel-ouaz          #+#    #+#             */
/*   Updated: 2024/07/16 01:07:11 by yel-ouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_two(t_node **head_a)
{
	if ((*head_a)->content > (*head_a)->next->content)
		sa(head_a);
}

int	get_max(t_node *head)
{
	int	i;
	int max;
	int position;

	max = head->index;
	position = 1;
	i = 1;
	while(head)
	{
		if (head->index > max)
		{
			max = head->index;
			position = i;
		}
		head = head->next;
		i++;
	}
	return (position);
}

int	get_min(t_node *head)
{
	int	i;
	int position;

	position = 1;
	while(head)
	{
		if (head->index == 1)
			return (position);
		head = head->next;
		position++;
	}
	return (position);
}

int	lst_size(t_node *head)
{
	int	i;

	i = 0;
	if (!head)
		return (0);
	while(head)
	{
		head = head->next;
		i++;
	}
	return (i);
}

void	top_a(t_node **head, int position)
{
	int	size;

	size = lst_size(*head);
	if (position == 1)
		return ;
	if (position == 2)
		sa(head);
	if (position <= (size / 2))
	{
		while(position > 1)
		{
			ra(head);
			position--;
		}
	}
	else
	{
		while(position < size + 1)
		{
			rra(head);
			position++;
		}
	}
}

void	top_b(t_node **head, int position)
{
	int	size;

	size = lst_size(*head);
	if (position == 1)
		return ;
	if (position == 2)
	{
		sb(head);
		return ;
	}
	if (position <= (size / 2))
	{
		while(position > 1)
		{
			rb(head);
			position--;
		}
	}
	else
		while(position < size + 1)
		{
			rrb(head);
			position++;
		}
}

int sorted(t_node *head)
{
	while(head->next)
	{
		if (head->index > head->next->index)
			return (0);
		head= head->next;
	}
	return (1);
}

void	sort_three(t_node **head_a)
{
	int max;

	max = get_max(*head_a);
	if (max == 2)
		rra(head_a);
	if (max == 1)
		ra(head_a);
	if ((*head_a)->content > (*head_a)->next->content)
		sa(head_a);
}

void sort_four(t_node **head_a, t_node **head_b)
{
	top_a(head_a, get_min(*head_a));
	if (sorted(*head_a))
		return ;
	pb(head_a, head_b);
	sort_three(head_a);
	pa(head_a, head_b);
}

void sort_five(t_node **head_a, t_node **head_b)
{
	top_a(head_a, get_min(*head_a));
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