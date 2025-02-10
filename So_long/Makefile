NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX = -Lmlx -lmlx_Linux -L/user/lib -lXext -lX11 -lm -lz
GNL_DIR = GNL
SRCS = so_long.c  so_long_utils.c $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c
OBJS = $(SRCS:.c=.o)

all:  $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME) $(MLX)

%.o: %.c
	$(CC) -I $(MLX) -I $(GNL_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all