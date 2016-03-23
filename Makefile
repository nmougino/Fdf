# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmougino <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/26 01:02:57 by nmougino          #+#    #+#              #
#    Updated: 2016/03/23 21:54:21 by nmougino         ###   ########.fr        #
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

NAME = fdf

MLXFLAGS = -framework OpenGL -framework AppKit

CFLAGS = -Wall -Wextra -Werror

all:
	@make -C libft/
	@mv libft/libft.a $(LIB)
	@make -C libdraw/
	@mv libdraw/libdraw.a $(LIB)
	@make $(NAME)

$(NAME):
	@echo "$(GRE)$(GRA)COMPILATION FDF$(DEF)"
	@gcc $(CFLAGS) -o $(NAME) $(SRC)/*.c -I$(INC) $(MLXFLAGS) $(LIB)/*.a
	
clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all glu use clean fclean re
