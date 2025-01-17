NAME = so_long
CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX = -Lminilibx -lmlx -lXext -lx11 -lm
SRCS = src/main.c src/utils.c src/game.c
OBJS = $(SRCS:.c=-o)

all: $(NAME)

$(NAME): $(OBJS)
	$(cc) $(CFLAGS) $(OBJS) $(MLX) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all