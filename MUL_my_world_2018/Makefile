NAME	=	my_world

CC	=	gcc -g3 $(CFLAGS)

RM	=	rm -f

SRC	=	main.c	\
		create_2d_map.c	\
		create_framebuffer.c	\
		create_line.c	\
		create_render.c	\
		draw_2d_map.c	\
		project_iso_point.c	\
		render_window.c	\
		analyse_events_choice.c	\
		chose_map_size.c	\
		draw_text.c	\
		initiate_game.c	\
		analyse_events.c	\
		slide_map.c	\
		use_tools.c	\
		create_render_image.c	\
		add_sprite_to_spritetab.c	\
		manage_game_click.c	\
		manage_time.c	\
		remove_sprite_from_spritetab.c	\
		check_altitude.c	\

SRCS	=	$(addprefix ./src/, $(SRC))

OBJS	=	$(SRCS:.c=.o)

LIB	=	-L./lib/my -lmy -lcsfml-graphics -lcsfml-window -lcsfml-system -lm

CFLAGS = -I./include
CFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	make -C lib/my
	$(CC) $(OBJS) -o $(NAME) $(LIB)

clean:
	$(RM) $(OBJS)

fclean: clean
	make -C lib/my fclean
	$(RM) $(NAME)

re: fclean all
