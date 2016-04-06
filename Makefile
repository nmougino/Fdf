# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/05 16:20:26 by nmougino          #+#    #+#              #
#    Updated: 2016/04/06 21:07:36 by nmougino         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	Compilator - clang est plus sur que gcc
CC =		clang
CFLAGS =	-Wall -Wextra -Werror
ADDFLAGS =	-framework OpenGL -framework Appkit

#	Binary
NAME =		fdf
LIBNAME =
DST =

#	Default rule
DEFRULE =	glu

#	Dossiers utiles
SRCDIR =	srcs
INCDIR =	includes
LIBDIR =	libs
OBJDIR =	objs

#	Liste des sources
SRC =		ctrl.c \
			ctrl_exit.c \
			ctrl_hight.c \
			ctrl_npfile.c \
			ctrl_rot.c \
			ctrl_trans.c \
			ctrl_zoom.c \
			data.c \
			err.c \
			get_next_line.c \
			iso.c \
			main.c \
			meta_init.c \
			parser.c
LIB =		ft draw mlx
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

#	SPECIAL RULES
moove:
	@echo "$(GRA)$(YEL)$(SOU)SPECIAL RULE: $@"
	mv libmlx/libmlx.a libs/
	@echo "$(DEF)"

#	Compilation rules
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS)	-c -o $@ $^ -I$(INCDIR)

$(OBJDIR):
	@echo "\n$(GRA)$(CYA)@ ++ Objects compilation$(DEF)"
	mkdir -p $(OBJDIR)

$(NAME): $(OBJDIR) $(OBJP) deplib
	make moove
	@echo "\n$(GRA)$(CYA)@ ++ $(NAME) compilation$(DEF)"
	$(CC) $(CFLAGS)	-o $@ $(OBJP) -I$(INCDIR) -L$(LIBDIR) $(LLIBP) $(ADDFLAGS)

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
