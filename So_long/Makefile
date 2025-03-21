NAME = so_long
NAME_B = Ultimate_so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX = -Lmlx -lmlx_Linux -L/user/lib -lXext -lX11 -lm -lz
GNL_DIR = GNL
L_DIR = Libft
S_DIR = srcs
B_DIR = bonus
LIBFT = $(L_DIR)/libft.a
SRCS = $(S_DIR)/so_long.c $(S_DIR)/so_long_utils.c $(S_DIR)/map_load_2.c\
	$(S_DIR)/map_load.c $(S_DIR)/moves.c $(S_DIR)/map_valid.c $(S_DIR)/flood_fill.c

OBJS = $(SRCS:.c=.o)

SRCS_B = $(B_DIR)/so_long.c $(B_DIR)/so_long_utils.c $(B_DIR)/map_load.c $(B_DIR)/map_load_2.c\
	$(B_DIR)/moves.c $(B_DIR)/map_valid.c $(B_DIR)/flood_fill.c $(B_DIR)/ultimate.c $(B_DIR)/ultimate_2.c $(B_DIR)/ultimate_3.c

OBJS_B = $(SRCS_B:.c=.o)

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L$(L_DIR) -lft -o $(NAME) $(MLX)

$(S_DIR)/%.o: $(S_DIR)/%.c
	$(CC) -I$(L_DIR) -c $< -o $@

$(LIBFT):
	make -C $(L_DIR)

bonus: $(LIBFT) $(NAME_B)

$(NAME_B): $(OBJS_B) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_B) -L$(L_DIR) -lft -o $(NAME_B) $(MLX)

clean:
	rm -f $(OBJS) $(OBJS_B)
	make clean -C $(L_DIR)

fclean: clean
	rm -f $(NAME) $(NAME_B)
	make fclean -C $(L_DIR)

re: fclean all