##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## compil my_popup
##

SRC	=	src/my_popup.c	\
		src/my_strlen.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_popup

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) -lncurses

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re: fclean all
