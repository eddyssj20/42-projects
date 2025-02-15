NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX = -Lmlx -lmlx_Linux -L/user/lib -lXext -lX11 -lm -lz
GNL_DIR = GNL
L_DIR = Libft
SRCS = so_long.c  so_long_utils.c map_load.c moves.c map_valid.c\
	$(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c\
	$(L_DIR)/libft_v1.c $(L_DIR)/libft_v2.c $(L_DIR)/libft_v3.c $(L_DIR)/libft_v4.c $(L_DIR)/libft_v5.c\
	$(L_DIR)/libft_v6.c $(L_DIR)/libft_v7.c $(L_DIR)/libft_v8.c
	
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