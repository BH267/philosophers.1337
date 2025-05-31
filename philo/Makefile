SRC = main.c hb_atou.c hb_isdigit.c makephilos.c list.c \
      hb_usleep.c routine.c monitor.c singlephilo.c \
      setandget.c forks.c

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
OBJ = $(SRC:.c=.o)

RM = rm -f

NAME = philo

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
