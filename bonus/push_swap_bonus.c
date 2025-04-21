/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-ouaz <yel-ouaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 14:47:36 by yel-ouaz          #+#    #+#             */
/*   Updated: 2024/08/06 19:31:42 by yel-ouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int argc, char **args)
{
	t_node	*head_a;
	t_node	*head_b;

	head_a = NULL;
	head_b = NULL;
	if (argc == 1)
		return (0);
	if (!check_args(argc, args))
		return (0);
	make_list(argc, args, &head_a);
	check_list(head_a);
	if (!exec_command(&head_a, &head_b))
	{
		free_list(head_a);
		free_list(head_b);
		write(2, "Error\n", 6);
		return (1);
	}
	if (head_a && sorted(head_a) && head_b == NULL)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_list(head_a);
	free_list(head_b);
}
