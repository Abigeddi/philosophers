NAME = philo
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = 	main.c \
		check_args.c \
		philo-timing.c \
		philo.c \
		philo.h


OBJ = $(SRC:%.c=%.o)

all : $(NAME)

$(NAME) : $(OBJ) philo.h
	$(CC) $(CFLAGS) $(obj) -O $@

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re :fclean all

