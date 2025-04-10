NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
L_DIR = Libft
LIBFT = $(L_DIR)/libft.a

SRCS = push_swap.c algoritmo.c numbers.c parse.c push_swap_utils.c\
		push.c reverse.c rotate.c sort_five.c sorter.c swap.c
	
OBJS = $(SRCS:.c=.o)

all:  $(LIBFT) $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L$(L_DIR) -lft -o $(NAME)

%.o: %.c
	$(CC) -I$(L_DIR) -c $< -o $@

$(LIBFT):
	make -C $(L_DIR)

clean:
	rm -f $(OBJS)
	make clean -C $(L_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(L_DIR)

re: fclean all

.PHONY: all clean fclean