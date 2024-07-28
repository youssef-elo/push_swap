/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-ouaz <yel-ouaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 16:05:51 by yel-ouaz          #+#    #+#             */
/*   Updated: 2024/07/28 17:22:24 by yel-ouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t			i;
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)s1;
	p2 = (unsigned char *)s2;
	i = 0;
	while (i < n && (p1[i] || p2[i]))
	{
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	return (0);
}

int	handle_command(char *str, t_node **head_a, t_node **head_b)
{
	if (ft_strncmp(str, "rra", 3) == 0)
		rra(head_a);
	else if (ft_strncmp(str, "rrb", 3) == 0)
		rrb(head_b);
	else if (ft_strncmp(str, "rrr", 3) == 0)
		rrr(head_a, head_b);
	else if (ft_strncmp(str, "sa", 2) == 0)
		sa(head_a);
	else if (ft_strncmp(str, "sb", 2) == 0)
		sb(head_b);
	else if (ft_strncmp(str, "ss", 2) == 0)
		ss(head_a, head_b);
	else if (ft_strncmp(str, "pb", 2) == 0)
		pb(head_a, head_b);
	else if (ft_strncmp(str, "pa", 2) == 0)
		pa(head_a, head_b);
	else if (ft_strncmp(str, "ra", 2) == 0)
		ra(head_a);
	else if (ft_strncmp(str, "rb", 2) == 0)
		rb(head_b);
	else if (ft_strncmp(str, "rr", 2) == 0)
		rr(head_a, head_b);
	else
		return (0);
	return (1);
}

int	exec_command(t_node **head_a, t_node **head_b)
{
	char	*command;

	command = get_next_line(0);
	while (command)
	{
		if (!handle_command(command, head_a, head_b))
		{
			free(command);
			return (0);
		}
		free(command);
		command = get_next_line(0);
	}
	return (1);
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
