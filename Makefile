#------------------ Srcs & Objs -------------------#

SRCS = parser.c map_check.c display_map.c so_long.c

MLX_FLAGS = -L$(MINILIB_DIR) -lmlx -lXext -lX11 -lm


#----------------- Constant namings ---------------------#

CC = cc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra

#------------------ LIBFT ------------------#

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

#------------------ MINILIB ------------------#

MINILIB_DIR = /usr/include/minilibx-linux

#--------------------- RULES --------------------#

all: $(LIBFT)
		cc $(CFLAGS) $(SRCS) $(MLX_FLAGS) $(LIBFT) -o so_long

$(LIBFT):
		@cd libft && make

clean:
		$(RM) #remove object files 
		@cd $(LIBFT_DIR) && make clean


fclean : clean
		#$(RM) $(SERVER_NAME) $(CLIENT_NAME)
		@cd $(LIBFT_DIR) && make fclean

re: fclean all

.PHONY: all clean fclean re
