##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## compil solostumper 1 
##

NAME	= 	sort_words

CC	= 	gcc -g3

RM	= 	rm -f

SRC	=	main.c	\
		parsing.c	\
		remove_str.c	\
		sorting.c	\
		my_putchar.c	\
		my_putstr.c

SRCS	=	$(addprefix ./src/, $(SRC)) 

OBJS	= 	$(SRCS:.c=.o)

CFLAGS 	= 	-I./include
CFLAGS 	+= 	-Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
