NAME = pipex
CC = gcc
CFLAGS = -Wall -Wextra -Werror

S_DIR = src
L_DIR = Libft
LIBFT = $(L_DIR)/libft.a

SRCS = $(S_DIR)/pipex.c $(S_DIR)/pipex_utils.c
OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L$(L_DIR) -lft -o $(NAME)
	echo "\n                 .\"-,.__"
	echo "                 \`.     \`.  ,"
	echo "              .--'  .._,'\"-' \`."
	echo "             .    .'         \`'"
	echo "             \`.   /          ,'"
	echo "               \`  '--.   ,-\"'"
	echo "                \`\"\`   |  \\"
	echo "                   -. \\, |"
	echo "                    \`--Y.'      ___."
	echo "                         \\     L._, \\"
	echo "               _.,        \`.   <  <\\                _"
	echo "             ,' '           \`, \`.   | \\            ( \`"
	echo "          ../, \`.            \`  |    .\\\`.           \\ \\_"
	echo "         ,' ,..  .           _.,'    ||\\l            )  '\"."
	echo "        , ,'   \\           ,'.-.`-._,'  |           .  _._\`."
	echo "      ,' /      \\ \\        \`' ' \`--/   | \\          / /   ..\\"
	echo "    .'  /        \\ .         |\\__ - _ ,'\\\` \`        / /     \`.\`."
	echo "    |  '          ..         \`-...-\"  |  \`-'      / /        . \`."
	echo "    | /           |L__           |    |          / /          \`. \`."
	echo "   , /            .   .          |    |         / /             \` \`"
	echo "  / /          ,. ,\`._ \`-_       |    |  _   ,-' /               \` \\"
	echo " / .           \\\"\`_/. \`-_ \\_,.  ,'    +-' \`-'  _,        ..,-.    \\\`."
	echo ".  '         .-f    ,'   \`    '.       \\__.---'     _   .'   '     \\ \\"
	echo "' /          \`.'    l     .' /          \\..      ,_|/   \`.  ,'\`     L\`"
	echo "|'      _.-\"\"\` \`.    \\ _,'  \`            \\ \`.___\`.'\"`-.  , |   |    | \\"
	echo "||    ,'      \`. \`.   '       _,...._        \`  |    \`/ '  |   '     .|"
	echo "||  ,'          \`. ;.,.---' ,'       \`.   \`.. \`-'  .-' /_ .'    ;_   ||"
	echo "|| '              V      / /           \`   | \`   ,'   ,' '.    !  \`. ||"
	echo "||/            _,-------7 '              . |  \`-'    l         /    \`||"
	echo ". |          ,' .-   ,' ||               | .-.        \`.      .'     ||"
	echo " \`'        ,'    \`\".'    |               |    \`.        '. -.'       \`'"
	echo "          /      ,'      |               |,'    \\-.._,.'/'"
	echo "          .     /        .               .       \\    .''"
	echo "        .\`.    |         \`.             /         :_,'.'"
	echo "          \\ \`...\\   _     ,'-.        .'         /_.-'"
	echo "           \`-.__ \`,  \`'   .  _.>----''.  _  __  /"
	echo "                .'        /\"'          |  \"'   '_"
	echo "               /_|.-'\\ ,\".             '.'\`__'-( \\"
	echo "                 / ,\"'\"\\,'               \`/  \`-.|\" mh"
	echo "\n PIPEX LISTO "


$(S_DIR)/%.o: $(S_DIR)/%.c
	$(CC) $(CFLAGS) -I $(L_DIR) -c $< -o $@

$(LIBFT):
	make -C $(L_DIR)

clean:
	rm -f $(OBJS)
	make clean -C $(L_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(L_DIR)

re: fclean all