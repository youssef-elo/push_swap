/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-ouaz <yel-ouaz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 22:12:55 by yel-ouaz          #+#    #+#             */
/*   Updated: 2024/07/16 01:31:19 by yel-ouaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int countDigits(int num) {
    int count = 0;

    if (num < 0)
        num = -num;
    do {
        num /= 10;
        count++;
    } while (num != 0);

    return count;
}
#define RED "\033[31m"
#define BLUE "\033[34m"
#define RESET "\033[0m"
void put_stack(t_node *head_a,t_node *head_b)
{
	int spaces;
	char *str = "                          ";
	printf(RED"/---------------------"BLUE"---------------------\\\n"RESET);
	printf(RED"|      STACK A       |"RESET);
	printf(BLUE"|      STACK B       |\n"RESET);
	printf(RED"\\---------------------"BLUE"---------------------/\n"RESET);
	while(head_a || head_b)
	{
		if (head_a)
		{
			spaces =  (22 - 4 - countDigits(head_a->content)) / 2;
			printf(RED"%.*s%d %d %.*s"RESET, spaces, str,head_a->content,head_a->index, spaces, str);
			head_a = head_a->next;
		}
		else if (!head_a)
			printf("                   ");
		if (head_b)
		{
			spaces =  (22 - 4 -  countDigits(head_b->content)) / 2;
			printf(BLUE"%.*s%d %d %.*s\n"RESET, spaces, str,head_b->content,head_b->index, spaces, str);
			head_b = head_b->next;
		}
		else if (!head_b)
			printf("\n");
	printf(RED". . . . . . . . . . . "BLUE". . . . . . . . . . . \n"RESET);
	}
}

int main(int argc, char **args)
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
		return (0);
	size = lst_size(head_a);
	if (size >=2 && size <= 5)
		small_sort(size, &head_a, &head_b);
	// put_stack(head_a, head_b);
}
//check for dupicates in the list done
//make the movements functions done
//sort it 

//sort four done
//sort five done
//sort the rest
//push
