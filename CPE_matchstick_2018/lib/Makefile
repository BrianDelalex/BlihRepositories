##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## compil my_printf and all dependencies
##

SRC	=	my_power.c	\
		my_putnbr.c	\
		my_putstr.c	\
		my_putchar.c	\
		my_strlen.c	\
		convert_to_binarie.c	\
		my_printf.c	\
		convert_to_octal.c	\
		my_strcpy.c	\
		convert_to_hexa.c	\
		check_and_print.c

SRCS	=	$(addprefix ./src/, $(SRC))

OBJ	=	$(SRCS:.c=.o)

CFLAGS += -I./include

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ) $(INCLUDE)

test:	$(OBJ)
	gcc -g3 -o my_printf $(OBJ) $(CFLAGS)
clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f *.gc* unit_tests

re: fclean all

tests_run:
	gcc -o unit_tests tests/test_my_printf.c $(SRCS) $(CFLAGS) --coverage -lcriterion
	./unit_tests
