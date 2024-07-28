/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tools_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-ouaz <yel-ouaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 14:55:56 by yel-ouaz          #+#    #+#             */
/*   Updated: 2024/07/28 14:47:49 by yel-ouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	make_list(int argc, char **argv, t_node **head)
{
	char	**split;
	long	check;
	int		i;
	int		j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		split = ft_split(argv[i], ' ');
		if (!split)
			ft_exit(NULL, head);
		while (split[j])
		{
			check = ft_atoi(split[j]);
			if (check > 2147483647 || check < -2147483648)
				ft_exit(split, head);
			if (!add_node(check, head))
				ft_exit(split, head);
			j++;
		}
		free_arr(split);
		i++;
	}
}

void	check_list(t_node *head)
{
	t_node	*i;
	t_node	*j;

	i = head;
	while (i)
	{
		j = head;
		while (j)
		{
			if (i != j)
			{
				if (i->content == j->content)
					ft_exit(NULL, &head);
				if (i->content > j->content)
					i->index++;
			}
			j = j->next;
		}
		i = i->next;
	}
}

void	free_list(t_node *head)
{
	t_node	*tmp;

	while (head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

int	add_node(int content, t_node **head)
{
	t_node	*node;
	t_node	*tmp;

	if (!head)
		return (0);
	node = malloc(sizeof(t_node));
	if (!node)
		return (0);
	node->content = content;
	node->index = 1;
	node->next = NULL;
	if (!(*head))
	{
		*head = node;
		return (1);
	}
	tmp = *head;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	return (1);
}

int	get_pos(t_node *head, int in)
{
	int	i;

	i = 1;
	while (head)
	{
		if (head->index == in)
			return (i);
		head = head->next;
		i++;
	}
	return (i);
}
