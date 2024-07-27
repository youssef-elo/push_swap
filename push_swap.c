/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-ouaz <yel-ouaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 22:12:55 by yel-ouaz          #+#    #+#             */
/*   Updated: 2024/07/27 15:28:42 by yel-ouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **args)
{
	t_node	*head_a;
	t_node	*head_b;
	int		size;

	head_a = NULL;
	head_b = NULL;
	if (argc == 1)
		return (0);
	if (!check_args(argc, args))
		return (0);
	make_list(argc, args, &head_a);
	check_list(head_a);
	if (sorted(head_a))
	{
		free_list(head_a);
		return (0);
	}
	size = lst_size(head_a);
	if (size >= 2 && size <= 5)
		small_sort(size, &head_a, &head_b);
	else
		the_rest(&head_a, &head_b);
	free_list(head_a);
}
//free list