# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/04/05 16:20:26 by nmougino          #+#    #+#              #
#    Updated: 2016/04/05 20:16:28 by nmougino         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#	Compilator
CC =		clang
CFLAGS =	-Wall -Wextra -Werror
ADDFLAGS =	-framework OpenGL -framework Appkit

#	Binary
NAME = fdf

#	Default rule
DEFRULE = glu

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

LIB =		ft \
			mlx \
			draw
LLIBS =		$(addprefix  -L$(LIBDIR) -l, $(LIB))
OBJ =		$(SRC:.c=.o)
OBJP =		$(addprefix $(OBJDIR)/, $(OBJ))

#	Couleurs
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

.PHONY = all glu $(NAME) $(OBJDIR) clean fclean re


# #
#	RULES
#

#	Main rules
default:
	@echo "\n\n$(GRA)$(GRE)			-*-  MAKEFILE  -*- \n$(BLU)  @nmougino$(DEF)\n"
	@echo "$(GRA)  DEFAULT RULE EXECUTION  :::  rule $(DEFRULE)$(DEF)"
	@make $(DEFRULE)
	@echo

all: $(OBJDIR) $(NAME)

re: fclean all

glu: re
	@make clean

$(OBJDIR):
	@echo "\n$(GRA)$(CYA)@ ++ Objects compilation$(DEF)"
	mkdir -p $(OBJDIR)

#	Lib rules
$(LIB):
	make -C lib$@/
	mv lib$@/lib$@.a $(LIBDIR)

#	Compilation rules
$(NAME): $(OBJP)
	@echo "$(GRA)$(GRE)@ ++ $(NAME) COMPILATION$(DEF)"
	$(CC) $(CFLAGS) -o $@ $^ -I$(INCDIR) $(LLIBS) $(ADDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	#$(CC) $(CFLAGS) -o $@ -c $< -I$(INCDIR) $(LLIBS) $(ADDFLAGS)
	$(CC) $(CFLAGS) -o $@ -c $< -I$(INCDIR)

#	MrProper's legacy
clean:
	@echo "\n$(RED)@ Objects deletion$(DEF)"
	rm -rf $(OBJDIR)

fclean: clean
	@echo "\n$(RED)@ Bin deletion$(DEF)"
	rm -f $(NAME)

