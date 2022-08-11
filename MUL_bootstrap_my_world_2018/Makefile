NAME	=	my_world

CC	=	gcc -g3 $(CFLAGS)

RM	=	rm -f

SRC	=	main.c	\
		render_window.c	\
		create_render.c	\
		analyse_events.c	\
		create_framebuffer.c	\
		project_iso_point.c	\
		create_2d_map.c	\
		create_line.c	\
		draw_2d_map.c	\

SRCS	=	$(addprefix ./src/, $(SRC))

OBJS	=	$(SRCS:.c=.o)

LIB	=	-L./lib -lmy -lcsfml-graphics -lcsfml-window -lcsfml-system -lm

CFLAGS = -I./include
CFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	make -C lib/
	$(CC) $(OBJS) -o $(NAME) $(LIB)

clean:
	$(RM) $(OBJS)

fclean: clean
	make -C lib/ fclean
	$(RM) $(NAME)

re: fclean all
