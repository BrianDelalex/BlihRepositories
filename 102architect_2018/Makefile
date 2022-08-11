##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## compil 102architect project
##

SRC	=	main.c	\
		parsing.c	\
		my_getnbr.c	\
		add_char_to_str.c	\
		my_strlen.c	\
		my_putchar.c	\
		my_putnbr.c	\
		create_matrix.c	\
		multiplie_matrix.c	\
		display_result.c	\
		my_rev_list.c	\
		handle_errors.c	\
		my_puterror.c	\
		my_int_to_str.c	\
		find_previous_flag_index.c	\
		create_base_matrix.c

SRCS	=	$(addprefix ./src/,$(SRC))

CFLAGS +=	-I./include

OBJ	=	$(SRCS:.c=.o)

NAME	=	102architect

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -g3 -o $(NAME) $(OBJ) $(CFLAGS) -lm

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f vgcore.*

re: fclean all
