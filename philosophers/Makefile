NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -g3 -fsanitize=address

SRCS = philosophers.c\
		//
	
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -lft -o $(NAME)

%.o: %.c
	$(CC) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re