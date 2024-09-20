NAME = so_long

C_FILES = main.c\
		check_map_file.c\
		destroy_and_exit.c\
		check_map.c\
		render.c\
		moves.c\
		player_move.c\
		flood_fill.c\

SRCS = $(addprefix sources/,$(C_FILES))

CFLAGS = -Wall -Wextra -Werror -g3

LIBS = printf/libftprintf.a libft/libft.a
DEPS = $(addprefix libs/,$(LIBS))

OBJS = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Iincludes -I/usr/include -Imlx -O3 -c $< -o $@

$(NAME): $(OBJS)
	make -C libs/mlx
	make -C libs/printf
	make -C libs/libft
	$(CC) $(OBJS) -Llibs/mlx -lmlx -Llibs/printf -lftprintf -Llibs/libft -lft -Iincludes  -L/usr/lib -Imlx -lXext -lX11 -lm -lz -o $(NAME)

clean:
	make -C libs/mlx clean
	make -C libs/printf clean
	make -C libs/libft clean
	rm -rf ${OBJS}


fclean: clean
	make -C libs/printf fclean
	make -C libs/libft fclean
	rm -f $(NAME)

re: fclean all

PHONY: all clean fclean re