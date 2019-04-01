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
SRCS = colors.c draw.c error.c events.c input.c main.c map.c pov.c window.c
OBJ = colors.o draw.o error.o events.o input.o main.o map.o pov.o window.o
FLAGS = -L minilibx_macos/ -lmlx -framework OpenGL -framework AppKit -o $(BINARY)
GCC = gcc
LIBS = ./libft/libft.a

all: $(BINARY)

$(BINARY):
	@echo "Compiling libraries and binary..."
	@make -C libft/
	@make -C minilibx_macos/
	@$(GCC) -g $(SRCS) -I/usr/X11/includes $(FLAGS) $(LIBS)
	@echo "Compiling Succesful."

clean:
	@echo "Cleaning object files..."
	@rm -rf $(OBJ)
	@make clean -C libft/
	@make clean -C minilibx_macos/
	@echo "Cleaning succesful."

fclean: clean
	@echo "Removing libraries and binary..."
	@rm -rf $(BINARY)
	@make fclean -C libft/
	@echo "Removing succesful."

re: fclean all
