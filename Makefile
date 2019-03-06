# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: nvreeke <nvreeke@student.codam.nl>           +#+                      #
#                                                    +#+                       #
#    Created: 2019/02/22 13:27:36 by nvreeke        #+#    #+#                 #
#    Updated: 2019/03/06 15:09:52 by wvan-dam      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

BINARY = fdf
SRCS = *.c
FLAGS = -L minilibx_macos/ -lmlx -framework OpenGL -framework AppKit -o $(BINARY)
GCC = gcc
LIBS = ./libft/libft.a

all: $(BINARY)

$(BINARY):
	$(GCC) -g $(SRCS) -I/usr/X11/includes $(FLAGS) $(LIBS)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(BINARY)

re: fclean all
