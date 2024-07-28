/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-ouaz <yel-ouaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 14:36:41 by yel-ouaz          #+#    #+#             */
/*   Updated: 2024/07/28 17:22:33 by yel-ouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= '0' && str[i] <= '9')
			|| str[i] == ' ' || str[i] == '-' || str[i] == '+')
			i++;
		else
			return (0);
	}
	return (1);
}

int	check_args(int argc, char **args)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!ft_is_digit(args[i]))
		{
			write(2, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}

long	ft_atoi(char *str)
{
	long	check;
	long	r;
	int		sign;
	int		i;

	sign = 1;
	i = 0;
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
	if (str[i])
		return (2147483650);
	return (r * sign);
}

void	free_arr(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	ft_exit(char **split, t_node **head)
{
	if (split)
		free_arr(split);
	if (head)
		free_list(*head);
	write(2, "Error\n", 6);
	exit(0);
}
