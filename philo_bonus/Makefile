SRC = main.c hb_atou.c hb_isdigit.c  hb_usleep.c singlephilo.c \
      makephilos.c list.c routine.c monitor.c \
      setandget.c forks.c ft_exit.c hb_malloc.c

CC = cc
CFLAGS = -Wall -Wextra -Werror -g # -fsanitize=thread
OBJ = $(SRC:.c=.o)

RM = rm -f

NAME = philo_bonus

all : $(NAME)

$(NAME) : $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o : %.c 
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@$(RM) $(OBJ) 

fclean : clean
	@$(RM) $(NAME)

re : fclean all

.PHONY : clean
