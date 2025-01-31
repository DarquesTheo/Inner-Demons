##
## EPITECH PROJECT, 2023
## makefile
## File description:
## makefile creating bin for CSFML project
##

NAME	:=	my_rpg

LIBNAME	:=	libprint.a

SRCLIB	:=	$(wildcard lib/*.c)

OBJLIB	:=	$(SRCLIB:.c=.o)

SRC	:=	$(wildcard src/*.c)						\
		$(wildcard src/init/*.c)				\
		$(wildcard src/UI/*.c)					\
		$(wildcard src/events/*.c)				\
		$(wildcard src/anims/*.c)				\
		$(wildcard src/on_each_fps/*.c)			\
		$(wildcard src/get_infos/*.c)			\
		$(wildcard src/player/*.c)				\
		$(wildcard src/player/weapons/*.c)		\
		$(wildcard src/utils/*.c)				\
		$(wildcard src/map/*.c)					\
		$(wildcard src/parsing/*.c)				\
		$(wildcard src/item/*.c)				\
		$(wildcard src/enemies/*.c)				\
		$(wildcard src/objects/*.c)				\
		$(wildcard src/anim_list/*.c)			\
		$(wildcard src/hitbox/*.c)				\
		$(wildcard src/sound_manager/*.c)		\
		$(wildcard src/res_manager/*.c)			\
		$(wildcard src/game_system/*.c)			\
		$(wildcard src/UI/button/*.c)			\
		$(wildcard src/UI/slider/*.c)		\
		$(wildcard src/UI/inventory/*.c)		\
		$(wildcard src/UI/inventory/interact/*.c)		\
		$(wildcard src/UI/shop/*.c)				\
		$(wildcard src/UI/heart/*.c)			\
		$(wildcard src/dialogue/*.c)			\
		$(wildcard src/hit_marker/*.c)			\
		$(wildcard src/game_struct/*.c)			\

OBJ	:=	$(SRC:.c=.o)

GRAPHIC	:=	-l csfml-graphics -lcsfml-system -lcsfml-window

AUDIO	:=	-l csfml-audio

CFLAGS	:=	-Wall -Wextra -I./include

LDFLAGS		:=	-L. -lprint

all : $(NAME)

create_lib	: $(OBJLIB)
	ar rc $(LIBNAME) $(OBJLIB)

fclean : clean
	rm -f $(NAME)
	rm -f $(LIBNAME)
	rm -f coding-style-reports.log

clean :
	find . -type f -name '*~' -delete
	find . -type f -name '#*#' -delete
	find . -type f -name '*.o' -delete

re : fclean all

debug : create_lib
	$(CC) $(SRC) $(GRAPHIC) $(AUDIO) $(CFLAGS) $(LDFLAGS) -lm -o $(NAME) -g3

$(NAME)	: create_lib $(OBJ)
	$(CC) $(OBJ) $(GRAPHIC) $(AUDIO) $(CFLAGS) $(LDFLAGS) -lm -o $(NAME)

.SILENT: create_lib $(OBJLIB) fclean clean

.PHONY : re fclean clean debug
