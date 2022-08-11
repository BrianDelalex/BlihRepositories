##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## compil my runner programm
##

NAME	= 	my_runner

CC	=	gcc -g3 $(CFLAGS)

RM	= 	rm -f

SRC	=	main.c	 \
		create_render.c	\
		analyse_events.c	\
		render_window.c	\
		create_render_image.c	\
		create_animation.c	\
		move_background.c	\
		handle_jump.c	\
		handle_anim_rate.c

SRCS	=	$(addprefix ./src/, $(SRC))

OBJS	=	$(SRCS:.c=.o)

CFLAGS 	=	-I./include
CFLAGS +=	-Wall -Wextra

LDFLAGS	=	-lcsfml-graphics -lcsfml-window -lcsfml-system

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
