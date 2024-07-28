/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-ouaz <yel-ouaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 14:35:49 by yel-ouaz          #+#    #+#             */
/*   Updated: 2024/07/27 14:39:37 by yel-ouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_back(t_node **head_a, t_node **head_b)
{
	int	biggest_pos;
	int	second_pos;
	int	size;

	while (*head_b)
	{
		size = lst_size(*head_b);
		biggest_pos = get_pos(*head_b, size);
		second_pos = get_pos(*head_b, size - 1);
		if (ft_closest(biggest_pos, second_pos, *head_b) == 2 && size > 2)
		{
			top_b(head_b, second_pos);
			pa(head_a, head_b);
			top_b(head_b, get_max(*head_b));
			pa(head_a, head_b);
			sa(head_a);
		}
		else
		{
			top_b(head_b, get_max(*head_b));
			pa(head_a, head_b);
		}
	}
}

// int	best_move(t_node *head, int chunk)
// {
// 	t_node	*tmp;
// 	int		first;
// 	int		last;
// 	int		i;

// 	1
// 	tmp = head;
// 	last = 0;
// 	first = 1;
// 	i = 1;
// 	while (head)
// 	{
// 		if (head->index <= chunk)
// 			break;
// 		head = head->next;
// 		first++;
// 	}
// 	while(tmp)
// 	{
// 		if (tmp->index <= chunk)
// 			last = i; 
// 		tmp = tmp->next;
// 		i++;
// 	}
// 	if (last == first)
// 		return (first);
// 	if (ft_closest(first, last, head) == 1)
// 		return (first);
// 	return (last);
// }

void	set_chunk(int size_a, int *chunk, int *i)
{
	*chunk = size_a / 4;
	*i = 25;
	if (size_a > 100)
	{
		*chunk = 55;
		*i = 55;
	}
}

void	push_chunks(t_node **head_a, t_node **head_b, int chunk, int i)
{
	t_node	*tempo;
	int		flag;
	int		j;

	(1) && (j = 0, flag = 0);
	while (*head_a)
	{
		tempo = *head_a;
		while (j <= chunk && tempo)
		{
			if (tempo->index <= chunk)
			{
				top_a(head_a, head_b, get_pos(*head_a, tempo->index), flag);
				flag = 0;
				pb(head_a, head_b);
				if ((*head_b)->next && ((*head_b)->index <= (chunk - (i / 2))))
					flag = 1;
				j++;
				tempo = *head_a;
			}
			else
				tempo = tempo->next;
		}
		chunk += i;
	}
}
