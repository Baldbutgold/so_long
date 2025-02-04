#------------------ Srcs & Objs -------------------#

SERVER_SRC = server.c
CLIENT_SRC = client.c

#------------------ LIBFT ------------------#

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

#----------------- Constant namings ---------------------#

CC = cc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra

SERVER_NAME = server
CLIENT_NAME = client

#--------------------- RULES --------------------#

all: $(SERVER_NAME) $(CLIENT_NAME)

$(LIBFT):
		@cd libft && make

$(SERVER_NAME): $(SERVER_SRC) $(LIBFT)
		$(CC) $(CFLAGS) $< $(LIBFT) -o $@

$(CLIENT_NAME): $(CLIENT_SRC) $(LIBFT)
		$(CC) $(CFLAGS) $< $(LIBFT) -o $@

clean:
		$(RM) $(SERVER_OBJS) $(CLIENT_OBJS)
		@cd $(LIBFT_DIR) && make clean

fclean: clean
		$(RM) $(SERVER_NAME) $(CLIENT_NAME)
		@cd $(LIBFT_DIR) && make fclean

re: fclean all

.PHONY: all clean fclean re

.SECONDARY: client.o server.o libft/libft.a
