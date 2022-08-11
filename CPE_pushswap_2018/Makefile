##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## compil pushswap project
##

MAIN	=	src/main.c

SRC	=	my_getnbr.c	\
		create_list.c	\
		operation.c	\
		operation2.c	\
		sorting.c	\
		my_putchar.c	\
		my_putnbr.c	\
		print_list.c	\
		my_putstr.c	\
		add_char_to_char.c	\
		my_strlen.c

TEST	=	test_operation.c	\
		my_int_to_str.c	\
		my_strlen.c	\
		add_char_to_str.c

TESTS	=	$(addprefix ./tests/, $(TEST))

SRCS	=	$(addprefix ./src/, $(SRC))

OBJ	=	$(SRCS:.c=.o)

TESTO	=	$(TESTS:.c=.o)

MAINO	=	$(MAIN:.c=.o)

CFLAGS	+= 	-I./include

NAME	=	push_swap

all: $(NAME)

$(NAME):	$(OBJ) $(MAINO)
	gcc -g3 -o $(NAME) $(MAINO) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)
	rm -f $(MAINO)

fclean:	clean
	rm -f $(NAME) $(TESTO) *.gc* unit_test vgcore.*

re:	fclean	all

tests_run:	$(OBJ)	$(TESTO)
	gcc -o unit_test $(OBJ) $(TESTO) $(CFLAGS) --coverage -lcriterion
	./unit_test
