# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-ouaz <yel-ouaz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/12 01:39:11 by yel-ouaz          #+#    #+#              #
#    Updated: 2024/07/27 15:52:53 by yel-ouaz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CFILES = sort.c\
		parser.c\
		moves_a.c\
		moves_b.c \
		ft_split.c \
		push_push.c \
		push_swap.c  \
		small_sort.c  \
		list_tools.c   \
		stack_tools.c   \
		moves_joint.c    \
		ft_split_tools.c  \

OFILES = $(CFILES:.c=.o)

FLAGS = -Wall -Werror -Wextra

all : $(OFILES) 
	cc $(OFILES) $(FLAGS) -o push_swap

%.o : %.c push_swap.h
	cc -c $(FLAGS) $<

clean :
	rm -rf $(OFILES)

fclean : clean
	rm -rf push_swap