NAME = libft.a

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = libft_v1.c libft_v2.c libft_v3.c libft_v4.c\
	libft_v5.c libft_v6.c libft_v7.c libft_v8.c\
	ft_printf_v1.c ft_printf_v2.c\
	get_next_line.c get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re