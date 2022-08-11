##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## compil my_sokoban
##

SRC	=	main.c	\
		check_map.c	\
		my_puterror.c	\
		my_putstr.c	\
		my_putchar.c	\
		find_nb_of_lines.c	\
		find_nb_of_cols.c	\
		create_map.c	\
		display_map.c	\
		handle_control.c	\
		check_next_pos.c	\
		create_vector_list.c	\
		handle_end.c	\
		check_box.c

SRCS	=	$(addprefix ./src/, $(SRC))

OBJ	=	$(SRCS:.c=.o)

CFLAGS	+=	-I./include

NAME	=	my_sokoban

all:	$(NAME)

$(NAME): $(OBJ)
	gcc -g3 -o $(NAME) $(OBJ) $(CFLAGS) -lncurses

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f vgcore.*
	rm -f *.gc*
	rm -f unit_test

re: fclean all

tests_run:
	gcc -o unit_test tests/test_map.c src/create_map.c src/create_vector_list.c src/find_nb_of_lines.c src/find_nb_of_cols.c -I./include --coverage -lcriterion -lncurses
	./unit_test
