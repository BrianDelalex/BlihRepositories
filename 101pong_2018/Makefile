##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## compil 101Pong project
##

SRC	=	101pong.c	\
		check_ball_bat_contact.c	\
		my_putchar.c	\
		my_puterror.c	\
		my_getnbr.c	\
		calcul_velocity.c	\
		my_putnbr.c	\
		my_strlen.c	\
		my_str_to_float.c	\
		my_putstr.c

SRCS	=	$(addprefix ./src/, $(SRC))

OBJ 	=	$(SRCS:.c=.o)

CFLAGS 	=	-I./include

NAME	=	101pong

all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS) -lm

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
re:	fclean all
