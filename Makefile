#------------------ Srcs & Objs -------------------#

SERVER_SRC = parser.c

CC = cc
RM = rm -f
#CFLAGS = -Wall -Werror -Wextra


#--------------------- RULES --------------------#

all: 
	cc parser.c libft.a -o parser
