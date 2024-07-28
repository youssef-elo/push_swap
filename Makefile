# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-ouaz <yel-ouaz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/12 01:39:11 by yel-ouaz          #+#    #+#              #
#    Updated: 2024/07/27 20:22:58 by yel-ouaz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CFILES = mandatory/sort.c\
		mandatory/parser.c\
		mandatory/moves_a.c\
		mandatory/moves_b.c \
		mandatory/ft_split.c \
		mandatory/push_push.c \
		mandatory/push_swap.c  \
		mandatory/small_sort.c  \
		mandatory/list_tools.c   \
		mandatory/stack_tools.c   \
		mandatory/moves_joint.c    \
		mandatory/ft_split_tools.c  \

OFILES = $(CFILES:.c=.o)

FLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(NAME) : $(OFILES) 
	cc $(OFILES) $(FLAGS) -o push_swap

mandatory/%.o : mandatory/%.c mandatory/push_swap.h
	cc -c $(FLAGS) $< -o $@

clean :
	rm -rf $(OFILES)

fclean : clean
	rm -rf push_swap

re : fclean all