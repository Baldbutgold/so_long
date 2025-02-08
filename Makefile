#------------------ Srcs & Objs -------------------#

SERVER_SRC = parser.c

CC = cc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra

INCLUDES = -I/usr/include -Imlx

MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

#--------------------- RULES --------------------#

# all: 
# 	cc $(CFLAGS) parser.c libft.a -o parser

mlx: test_window.c
	cc test_window.c libmlx.a -Lmlx -L/usr/lib/X11 -lXext -lX11 -o ./test_window

# $(NAME): $(OBJS)
# 	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX_FLAGS)
# .c.o:
# 	$(CC) $(CFLAGS) -c -o $@ $< $(INCLUDES)
