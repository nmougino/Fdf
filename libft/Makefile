# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/06 20:45:24 by nmougino          #+#    #+#              #
#    Updated: 2016/04/06 22:29:40 by nmougino         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	Compilator - clang est plus sur que gcc
CC =		clang
CFLAGS =	-Wall -Wextra -Werror
ADDFLAGS =	-framework OpenGL -framework Appkit

#	Binary
NAME =
LIBNAME =	libft.a
DST =		../libs/

#	Default rule
DEFRULE =	glulib

#	Dossiers utiles
SRCDIR =	.
INCDIR =	../includes
LIBDIR =	libs
OBJDIR =	objs

#	Liste des sources
SRC =		ft_abs.c \
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
LIB =		ft mlx
OBJ =		$(SRC:.c=.o)

#	Prefixes
LLIBP =		$(addprefix -l, $(LIB))
LIBP =		$(addprefix lib, $(LIB))
OBJP =		$(addprefix $(OBJDIR)/, $(SRC:.c=.o))

#	Couleurs
DEF =		\033[0m
GRA =		\033[1m
SOU =		\033[4m
BLI =		\033[5m
BLA =		\033[30m
RED =		\033[31m
GRE =		\033[32m
YEL =		\033[33m
BLU =		\033[34m
PUR =		\033[35m
CYA =		\033[36m
WHI =		\033[37m

define \n


endef

# #
#	RULES
#

.PHONY = default glu glulib all alllib re relib $(OBJDIR) $(NAME) lib deplib clean fclean

#	Main rules
default:
	@echo "\n\n$(GRA)$(GRE)			-*-  MAKEFILE  -*- \n$(BLU)  @nmougino$(DEF)\n"
	@echo "$(GRA)  DEFAULT RULE EXECUTION  :::  rule $(DEFRULE)$(DEF)"
	@$(addprefix make ,$(DEFRULE))
	@echo "FIN DU PROGRAMME COMPILATION TERMINEE"

glu: re
	make clean

glulib: relib
	make clean

all: $(NAME)

alllib: lib

re: fclean all

relib: fclean alllib

#	Compilation rules
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS)	-c -o $@ $^ -I$(INCDIR)

$(OBJDIR):
	@echo "\n$(GRA)$(CYA)@ ++ Objects compilation$(DEF)"
	mkdir -p $(OBJDIR)

$(NAME): $(OBJDIR) $(OBJP) deplib
	@echo "\n$(GRA)$(CYA)@ ++ $(NAME) compilation$(DEF)"
	$(CC) $(CFLAGS)	-o $@ $(OBJP) -I$(INCDIR) -L$(LIBDIR) $(LLIBP)

lib: $(OBJDIR) $(OBJP)
	@echo "\n$(PUR)@ Library indexation$(DEF)"
	ar rc $(DST)$(LIBNAME) $(OBJP)
	ranlib $(DST)$(LIBNAME)

deplib:
	$(addprefix make -C ,$(addsuffix /$(\n), $(LIBP)))
	
#	MrProper's legacy
clean:
	@echo "\n$(RED)@ Objects deletion$(DEF)"
	rm -rf $(OBJDIR)

fclean: clean
	@echo "\n$(RED)@ Binary deletion$(DEF)"
	@rm -f $(NAME)
	@rm -f $(LIBNAME)
