# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahel-mou <ahel-mou@1337.ma>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/31 15:50:39 by ahel-mou          #+#    #+#              #
#    Updated: 2022/02/13 04:07:01 by ahel-mou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
NAME_B = philo_bonus
CC = cc

FLAGS = -Wall -Wextra -Werror

SRC = ./philo_m/philo.c\
	./philo_m/ft_atoi.c\
	./philo_m/init_philos_forks.c\
	./philo_m/ph_life.c\
	./philo_m/death_check.c\
	./philo_m/time_handlers.c\

SRC_B = ./philo_b/semaphores_utils.c\
	./philo_b/child_processes.c\
	./philo_b/ft_atoi.c\
	./philo_b/philo_bonus.c\
	./philo_b/death_check.c\
	./philo_b/ph_life.c\
	./philo_b/time_handlers.c\
	
OBJ = $(SRC:.c=.o)
OBJ_B = $(SRC_B:.c=.o)


all: $(NAME) b

$(NAME): $(OBJ)
		$(CC) $(FLAGS) $(OBJ) -o $(NAME)

b : $(OBJ_B)
		$(CC) $(FLAGS) $(OBJ_B) -o $(NAME_B)
clean:
	rm -f $(OBJ)

fclean: clean
	find . -name "*.o" -delete
	rm -f $(NAME) $(NAME_B)

re: fclean all

.PHONY: all clean fclean re
