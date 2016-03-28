# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmougino <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/02/26 01:02:57 by nmougino          #+#    #+#              #
#    Updated: 2016/03/28 21:41:36 by nmougino         ###   ########.fr        #
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

SRC =	ft_abs.c \
		ft_atoi.c \
		ft_bzero.c \
		ft_getlinesize.c \
		ft_getlline.c \
		ft_getnbrline.c \
		ft_gotoline.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_atoi.c \
		ft_bzero.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_islow.c \
		ft_isprint.c \
		ft_isup.c \
		ft_itoa.c \
		ft_linesplit.c \
		ft_lstadd.c \
		ft_lstdel.c \
		ft_lstdelone.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_lstnew.c \
		ft_memalloc.c \
		ft_memccpy.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memdel.c \
		ft_memmove.c \
		ft_memset.c \
		ft_min.c \
		ft_nbrlen.c \
		ft_pow.c \
		ft_putchar.c \
		ft_putchar_fd.c \
		ft_putendl.c \
		ft_putendl_fd.c \
		ft_putnbr.c \
		ft_putnbrendl.c \
		ft_putnbr_fd.c \
		ft_putnbrendl_fd.c \
		ft_putstr.c \
		ft_putstr_fd.c \
		ft_sqrt.c \
		ft_stradd.c \
		ft_strcat.c \
		ft_strchr.c \
		ft_strclr.c \
		ft_strcmp.c \
		ft_strcpy.c \
		ft_strdel.c \
		ft_strdup.c \
		ft_strequ.c \
		ft_striter.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlen.c \
		ft_strmap.c \
		ft_strmapi.c \
		ft_strncat.c \
		ft_strncmp.c \
		ft_strncpy.c \
		ft_strnequ.c \
		ft_strnew.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strrev.c \
		ft_strsplit.c \
		ft_strstr.c \
		ft_strsub.c \
		ft_strtrim.c \
		ft_swapchar.c \
		ft_swapint.c \
		ft_tolower.c \
		ft_toupper.c

INC = .

CFLAGS = -Wall -Wextra -Werror

OBJ = $(SRC:.c=.o)

NAME = libft.a

glu:
	@echo "\n$(GRA)$(CYA) EXECUTION RULE 'GLU'$(DEF)"
	@make fclean
	@echo "$(GRA)$(BLA) * compilation des sources$(DEF)"
	@gcc -c $(CFLAGS) $(SRC) -I$(INC)
	@echo "$(GRA)$(BLA) * ecriture et indexation$(DEF)"
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@make clean
	@echo "$(GRA)$(GRE) Done$(DEF)"

all: $(NAME)

$(NAME):
	@echo "creation des fichier objet ..."
	@gcc $(CFLAGS) -c $(SRC) -I$(LIB)
	@echo "ecriture et indexation de la librairie ..."
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@echo "$(RED) - suppression objets$(DEF)"
	@rm -f $(OBJ)

fclean: clean
	@echo "$(RED) - suppression librairie$(DEF)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all glu clean fclean re
