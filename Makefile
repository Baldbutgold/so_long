#------------------ Srcs & Objs -------------------#

SERVER_SRC = parser.c

CC = cc
RM = rm -f
#CFLAGS = -Wall -Werror -Wextra

INCLUDES = -I/usr/include -Imlx

MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

#--------------------- RULES --------------------#

# all: 
# 	cc $(CFLAGS) parser.c libft.a -o parser

all:
	cc -Wall -Werror -Wextra so_long.c parser.c map_check.c display_map.c libft.a libmlx.a -Lmlx -L/usr/lib/X11 -lXext -lX11 -o so_long -g3
# all: so_long.c map_check.c parser.c
# 	cc parser.c so_long.c map_check.c libft.a -o so_long

mlx: test_window.c
	cc test_window.c libmlx.a -Lmlx -L/usr/lib/X11 -lXext -lX11 -o ./test_window

re: retest_window.c
	cc retest_window.c libmlx.a -Lmlx -L/usr/lib/X11 -lXext -lX11 -o ./retest_window
# $(NAME): $(OBJS)
# 	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)
# .c.o:
# 	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)
