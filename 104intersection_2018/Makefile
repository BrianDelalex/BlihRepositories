##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## compil 104intersection project
##

NAME	=	104intersection

CC	= 	gcc -g3

RM	= 	rm -f

SRC	=	main.c	\
		handle_errors.c	\
		my_puterror.c	\
		my_getnbr.c	\
		parsing.c	\
		check_intersection_sphere.c	\
		display_info.c	\
		check_intersection_cylinder.c	\
		check_intersection_cone.c

SRCS	= 	$(addprefix ./src/, $(SRC))

OBJS	= 	$(SRCS:.c=.o)

CFLAGS 	= 	-I./include 
CFLAGS += 	-Wall -Wextra

LDFLAGS	=	-lm

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
