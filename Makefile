# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-ouaz <yel-ouaz@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/12 01:39:11 by yel-ouaz          #+#    #+#              #
#    Updated: 2024/08/03 20:40:41 by yel-ouaz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BONUS = checker

FLAGS = -Wall -Werror -Wextra

MFILES = mandatory/sort.c\
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

BFILES =bonus/read_exec.c    \
		bonus/parser_bonus.c  \
		bonus/moves_b_bonus.c  \
		bonus/moves_a_bonus.c   \
		bonus/ft_split_bonus.c   \
		bonus/push_swap_bonus.c   \
		bonus/list_tools_bonus.c   \
		bonus/moves_joint_bonus.c   \
		bonus/gnl/get_next_line.c    \
		bonus/ft_split_tools_bonus.c  \
		bonus/gnl/get_next_line_utils.c\

BOFILES = $(BFILES:.c=.o)

OFILES = $(MFILES:.c=.o)

all : $(NAME)

bonus : $(BONUS)

$(NAME) : $(OFILES) 
	cc $(OFILES) $(FLAGS) -o $(NAME)

$(BONUS) : $(BOFILES)
	cc $(BOFILES) $(FLAGS) -o $(BONUS)

mandatory/%.o : mandatory/%.c mandatory/push_swap.h
	cc -c $(FLAGS) $< -o $@

bonus/%.o : bonus/%.c bonus/push_swap_bonus.h bonus/gnl/get_next_line.h
	cc -c $(FLAGS) $< -o $@

clean :
	rm -rf $(OFILES) $(BOFILES)

fclean : clean
	rm -rf $(NAME) $(BONUS)

re : fclean all
