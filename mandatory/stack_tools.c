/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-ouaz <yel-ouaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 14:29:20 by yel-ouaz          #+#    #+#             */
/*   Updated: 2024/08/03 20:41:15 by yel-ouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max(t_node *head)
{
	int	position;
	int	max;
	int	i;

	max = head->index;
	position = 1;
	i = 1;
	while (head)
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
	t_node	*tmp;
	int		position;
	int		smallest_index;

	tmp = head;
	position = 1;
	smallest_index = 10;
	while (tmp)
	{
		if (tmp->index < smallest_index)
			smallest_index = tmp->index;
		tmp = tmp->next;
	}
	while (head)
	{
		if (head->index == smallest_index)
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
	while (head)
	{
		head = head->next;
		i++;
	}
	return (i);
}

int	sorted(t_node *head)
{
	while (head->next)
	{
		if (head->index > head->next->index)
			return (0);
		head = head->next;
	}
	return (1);
}

int	ft_closest(int big, int second, t_node *head)
{
	int	size;

	size = lst_size(head);
	if (big > (size / 2))
		big = size - big + 1;
	else
		big--;
	if (second > (size / 2))
		second = size - second + 1;
	else
		second--;
	if (second > big)
		return (1);
	return (2);
}
