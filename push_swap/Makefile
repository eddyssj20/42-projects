NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
L_DIR = Libft
SRCS = push_swap.c
	$(L_DIR)/libft_v1.c $(L_DIR)/libft_v2.c $(L_DIR)/libft_v3.c $(L_DIR)/libft_v4.c $(L_DIR)/libft_v5.c\
	$(L_DIR)/libft_v6.c $(L_DIR)/libft_v7.c $(L_DIR)/libft_v8.c $(L_DIR)/ft_printf_v1.c $(L_DIR)/ft_printf_v2.c
	
OBJS = $(SRCS:.c=.o)

all:  $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) -I $(GNL_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all