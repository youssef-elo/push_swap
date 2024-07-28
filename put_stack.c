// #include <stdio.h>
// #include "push_swap.h"

// #define RED "\033[31m"
// #define BLUE "\033[34m"
// #define RESET "\033[0m"

// int countDigits(int num) {
//     int count = 0;

//     if (num < 0)
//         num = -num;
//     do {
//         num /= 10;
//         count++;
//     } while (num != 0);

//     return count;
// }

// void put_stack(t_node *head_a,t_node *head_b)
// {
// 	int spaces;
// 	char *str = "                          ";
// 	dprintf(2, RED"/---------------------"BLUE"---------------------\\\n"RESET);
// 	dprintf(2, RED"|      STACK A       |"RESET);
// 	dprintf(2, BLUE"|      STACK B       |\n"RESET);
// 	dprintf(2, RED"\\---------------------"BLUE"---------------------/\n"RESET);
// 	while(head_a || head_b)
// 	{
// 		if (head_a)
// 		{
// 			spaces =  (22 - 4 - countDigits(head_a->content)) / 2;
// 			dprintf(2, RED"%.*s%d %d %.*s"RESET, spaces, str,head_a->content,head_a->index, spaces, str);
// 			head_a = head_a->next;
// 		}
// 		else if (!head_a)
// 			dprintf(2, "                   ");
// 		if (head_b)
// 		{
// 			spaces =  (22 - 4 -  countDigits(head_b->content)) / 2;
// 			dprintf(2, BLUE"%.*s%d %d %.*s\n"RESET, spaces, str,head_b->content,head_b->index, spaces, str);
// 			head_b = head_b->next;
// 		}
// 		else if (!head_b)
// 			dprintf(2, "\n");
// 	dprintf(2, RED". . . . . . . . . . . "BLUE". . . . . . . . . . . \n"RESET);
// 	}
// }
