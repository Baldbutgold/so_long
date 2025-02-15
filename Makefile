#------------------ Srcs & Objs -------------------#

SRCS = parser.c check_map.c display_map.c so_long.c
OBJS = $(SRCS:.c=.o)

#----------------- Constant namings ---------------------#

CC = cc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra

#------------------ Library Paths ------------------#

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MINILIB_DIR = /usr/include/minilibx-linux
MLX_FLAGS = -L$(MINILIB_DIR) -lmlx -lXext -lX11 -lm

#--------------------- RULES --------------------#

NAME = so_long

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
		$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) $(LIBFT) -o $(NAME)

$(LIBFT):
		@cd libft && make

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS)
		@cd $(LIBFT_DIR) && make clean


fclean : clean
		$(RM) $(NAME)
		@cd $(LIBFT_DIR) && make fclean

re: fclean all

.PHONY: all clean fclean re
