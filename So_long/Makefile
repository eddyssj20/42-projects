NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX = -Lmlx -lmlx_Linux -L/user/lib -lXext -lX11 -lm -lz
GNL_DIR = GNL
L_DIR = Libft
SRCS = so_long.c  so_long_utils.c map_load.c $(GNL_DIR)/get_next_line.c $(GNL_DIR)/get_next_line_utils.c\
	$(L_DIR)/ft_atoi.c $(L_DIR)/ft_bzero.c $(L_DIR)/ft_calloc.c $(L_DIR)/ft_isalnum.c\
	$(L_DIR)/ft_isalpha.c $(L_DIR)/ft_isascii.c $(L_DIR)/ft_isprint.c $(L_DIR)/ft_memchr.c\
	$(L_DIR)/ft_memcmp.c $(L_DIR)/ft_memcpy.c $(L_DIR)/ft_memmove.c $(L_DIR)/ft_memset.c\
	$(L_DIR)/ft_strchr.c $(L_DIR)/ft_strdup.c $(L_DIR)/ft_strjoin.c $(L_DIR)/ft_strlcat.c\
	$(L_DIR)/ft_strlcpy.c $(L_DIR)/ft_strlen.c $(L_DIR)/ft_strncmp.c $(L_DIR)/ft_strnstr.c\
	$(L_DIR)/ft_strrchr.c $(L_DIR)/ft_strtrim.c $(L_DIR)/ft_substr.c $(L_DIR)/ft_tolower.c\
	$(L_DIR)/ft_toupper.c $(L_DIR)/ft_split.c $(L_DIR)/ft_itoa.c $(L_DIR)/ft_strmapi.c\
	$(L_DIR)/ft_striteri.c $(L_DIR)/ft_putchar_fd.c $(L_DIR)/ft_putstr_fd.c $(L_DIR)/ft_putendl_fd.c\
	$(L_DIR)/ft_putnbr_fd.c $(L_DIR)/ft_isdigit.c
	
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