##
## EPITECH PROJECT, 2019
## Makefile
## File description
## Makefile for generator
##

NAME	=	generator

CC	=	gcc -g3 $(CFLAGS)

RM	=	rm -f

SRC	=	main.c	\
		initialize_map.c	\
		initiate_perfect_map.c	\

SRCS	=	$(addprefix ./src/, $(SRC))

OBJS	=	$(SRCS:.c=.o)

LIB	=	-L../lib -lmy

CFLAGS = -I./include
CFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	make -C ../lib/
	$(CC) $(OBJS) -o $(NAME) $(LIB)

clean:
	$(RM) $(OBJS)

fclean: clean
	make -C ../lib/ fclean
	$(RM) $(NAME)

re: fclean all
