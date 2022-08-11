##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## compil bsq project
##

SRC	=	main.c	\
		bsq.c	\
		find_square_param.c	\
		find_biggest_square.c	\
		is_square_of_size.c	\
		my_putstr.c	\
		my_puterror.c	\
		my_putchar.c	\
		create_map.c	\
		find_nb_of_line.c	\
		find_nb_of_col.c	\
		load_2d_array_from_file.c

SRCS	=	$(addprefix ./src/, $(SRC))

OBJ	=	$(SRCS:.c=.o)

CFLAGS +=	-I./include

NAME 	=	bsq

all: $(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
