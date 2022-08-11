##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## compil 103cipher project
##

SRC	=	main.c	\
		handle_errors.c	\
		my_puterror.c	\
		my_putstr.c	\
		my_putchar.c	\
		create_key.c	\
		my_strlen.c	\
		create_message.c	\
		multiplie_matrix.c	\
		display_result.c	\
		create_invert_key.c	\
		my_getdigit.c	\
		invert_matrix_2.c	\
		display_result2.c	\
		multiplie_matrix4.c

SRCS	=	$(addprefix ./src/, $(SRC))

OBJ	=	$(SRCS:.c=.o)

CFLAGS	+=	-I./include

NAME	=	103cipher

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -g3 -o $(NAME) $(OBJ) $(CFLAGS) -lm

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all
