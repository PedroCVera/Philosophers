# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pcoimbra <pcoimbra@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 14:11:28 by pcoimbra          #+#    #+#              #
#    Updated: 2022/12/13 17:57:09 by pcoimbra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=	cc
CFLAGS		=	-Wall -Wextra -Werror -g #-fsanitize=thread
RM			=	rm -f

NAME		=	philo

INCLUDE		=	-I ./ -pthread

SRCS_		=	srcs/philo.c \
					utils/utils1.c \
					srcs/init_philo.c \
					srcs/checker.c \
					utils/death+print.c \
					utils/routine_utils.c \
					errors/error_handler1.c

SRCS		=	$(addprefix $(_SRC), $(SRCS_))

OBJS		=	$(patsubst %.c, %.o, $(SRCS))
all:		$(NAME)

$(_OBJ)%.o: $(_SRC)%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(_OBJ) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(INCLUDE)

$(_OBJ):
	mkdir $@

clean:
	$(RM) -r $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re