# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmougino <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/26 01:02:57 by nmougino          #+#    #+#              #
#    Updated: 2016/04/04 22:09:31 by nmougino         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COULEURS
#

DEF		= \033[0m
GRA		= \033[1m
SOU		= \033[4m
BLI		= \033[5m
BLA		= \033[30m
RED		= \033[31m
GRE		= \033[32m
YEL		= \033[33m
BLU		= \033[34m
PUR		= \033[35m
CYA		= \033[36m
WHI		= \033[37m

SRC =	srcs
INC =	includes
LIB =	libs

SRCS =	$(SRC)/ctrl.c \
		$(SRC)/ctrl_exit.c \
		$(SRC)/ctrl_hight.c \
		$(SRC)/ctrl_npfile.c \
		$(SRC)/ctrl_rot.c \
		$(SRC)/ctrl_trans.c \
		$(SRC)/ctrl_zoom.c \
		$(SRC)/data.c \
		$(SRC)/err.c \
		$(SRC)/get_next_line.c \
		$(SRC)/iso.c \
		$(SRC)/main.c \
		$(SRC)/meta_init.c \
		$(SRC)/parser.c
LIBS =	-lft -lmlx -ldraw

NAME = fdf

MLXFLAGS = -framework OpenGL -framework AppKit

CFLAGS = -Wall -Wextra -Werror

$(NAME):
	@echo "$(GRE)$(GRA)COMPILATION FDF$(DEF)"
	gcc $(CFLAGS) -o $(NAME) $(SRCS) -I$(INC) $(MLXFLAGS) -L$(LIB) $(LIBS)

all: lib
	make $(NAME)

lib:
	@mkdir -p libs
	@make -C libft/
	@mv libft/libft.a $(LIB)/
	@make -C libdraw/
	@mv libdraw/libdraw.a $(LIB)/
	@make -C minilibx_macos
	@mv minilibx_macos/libmlx.a $(LIB)/

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

glu: fclean $(NAME)

re: fclean all

.PHONY: $(NAME) all glu lib use clean fclean re
	ctrl.c
	ctrl_exit.c
	ctrl_hight.c
	ctrl_npfile.c
	ctrl_trans.c
	ctrl_zoom.c
	data.c
	err.c
	get_next_line.c
	iso.c
	main.c
	meta_init.c
	parser.c
