/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-ouaz <yel-ouaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 22:12:12 by yel-ouaz          #+#    #+#             */
/*   Updated: 2024/07/14 01:24:18 by yel-ouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_is_digit(char *str)
{
	int i;

	i = 0;
	while(str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9')
			|| str[i] == ' ' || str[i] == '-' || str[i] == '+')
			i++;
		else
			return (0);
	}
	return (1);
}

int check_args(int argc, char **args)
{
	int i;

	i = 1;
	while(i < argc)
	{
		if(!ft_is_digit(args[i]))
			return (0);
		i++;
	}
	return (1);
}

int	add_node(int content, t_node **head)
{
	t_node *node;
	t_node *tmp;
	
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
	while(tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	return (1);
}

long	ft_atoi(char *str)
{
	int		i;
	int		sign;
	long	r;
	long	check;

	i = 0;
	sign = 1;
	r = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i++] == '-')
			sign *= -1;
	}
	while (str[i] <= '9' && str[i] >= '0')
	{
		check = r * 10 + (str[i] - 48);
		if (check < r)
			return (2147483650);
		r *= 10;
		r += (str[i] - 48);
		i++;
	}
	return (r * sign);
}

void free_list(t_node *head)
{
	t_node	*tmp;

	while(head)
	{
		tmp = head->next;
		free(head);
		head = tmp;
	}
}

void free_arr(char **split)
{
	int		i;

	i = 0;
	while(split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void ft_exit(char **split, t_node **head)
{
	if (split)
		free_arr(split);
	if (head)
		free_list(*head);
	write(1, "Error\n", 6);
	exit(0);
}

void	make_list(int argc, char **argv, t_node **head)
{
	char	**split;
	int		i;
	int		j;
	long	check;

	i = 1;
	while(i < argc)
	{
		j = 0;
		split = ft_split(argv[i], ' ');
		if (!split)
			ft_exit(NULL, head);
		while(split[j])
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

void check_list(t_node *head)
{
	t_node	*i;
	t_node	*j;

	i = head;
	while(i)
	{
		j = head;
		while(j)
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