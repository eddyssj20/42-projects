NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror
CFLAGS += -g3 -fsanitize=address

SRCS_DIR = srcs
SRCS = $(SRCS_DIR)/philo.c $(SRCS_DIR)/parse.c $(SRCS_DIR)/utils.c $(SRCS_DIR)/cleanup.c $(SRCS_DIR)/data.c $(SRCS_DIR)/monitor.c $(SRCS_DIR)/routine.c $(SRCS_DIR)/sim.c
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
