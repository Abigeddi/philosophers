# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abigeddi <abigeddi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/16 19:45:08 by abigeddi          #+#    #+#              #
#    Updated: 2022/08/17 18:44:09 by abigeddi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = philo
CC = gcc
CFLAGS =  -Wall -Wextra -Werror 
SRC = 	main.c \
		check_args.c \
		eat_checker.c \
		philo.c 


OBJ = $(SRC:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJ)
	gcc $(CFLAGS) $^ -o $@

%.o : %.c
	gcc $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re :fclean all

