NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
L_DIR = Libft
LIBFT = $(L_DIR)/libft.a

SRCS = push_swap.c
	
OBJS = $(SRCS:.c=.o)

all:  $(LIBFT) $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(OBJS) -L$(L_DIR) -lft -o $(NAME)

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