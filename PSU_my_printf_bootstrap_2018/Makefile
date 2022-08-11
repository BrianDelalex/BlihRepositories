##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## compil boootstrap_my_printf
##

SRC	=	sum_stdarg.c	\
		my_strlen.c	\
		dist_stdarg.c	\
		my_putnbr.c	\
		my_putchar.c	\
		my_putstr.c

SRCS	= 	$(addprefix ./src/, $(SRC))

OBJ	=	$(SRCS:.c=.o)

CFLAGS += -I./include

NAME = libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)

clean:	
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) unit_tests *.gc*

tests_run:
	  gcc -o unit_tests tests/test_stdarg.c $(SRCS) $(CFLAGS) --coverage -lcriterion
	  ./unit_tests
