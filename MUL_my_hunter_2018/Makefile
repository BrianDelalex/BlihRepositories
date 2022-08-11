##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## compil my_hunter project
##

SRC	=	main.c	\
		create_render_image.c	\
		analyse_events.c	\
		create_render_window.c	\
		create_animation.c	\
		my_putnbr.c	\
		my_putchar.c	\
		my_putstr.c	\
		time_anim.c	\
		handle_duck_move.c	\
		handle_duck_death.c	\
		create_random_value.c	\
		create_scoreboard.c	\
		my_int_to_str.c		\
		add_char_to_str.c	\
		my_getnbr.c	\
		my_strlen.c	\
		my_strcpy.c

SRC_TEST	=	tests/test_int_to_str.c	\
			src/my_int_to_str.c	\
			src/add_char_to_str.c	\
			src/my_strlen.c	\
			src/my_getnbr.c

SRCS	=	$(addprefix ./src/, $(SRC))

OBJ	=	$(SRCS:.c=.o)

NAME	=	my_hunter

GRAPH	=	-lc_graph_prog

CFLAGS += 	-I./include

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -g3 -o $(NAME) $(SRCS) $(CFLAGS) $(GRAPH)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f *.gc* unit_tests

re: fclean all

tests_run:
	gcc -o unit_tests $(SRC_TEST) --coverage -lcriterion
	./unit_tests
