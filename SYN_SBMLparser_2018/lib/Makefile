##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

CC	:=	gcc -g3 #-coverage

NAME	:=	libmy.a

LDFLAGS	:=	-g

CFLAGS	+=	-I include/ -g -Wall -Wextra

RM	:=	rm -rf

SRC := $(wildcard src/*.c src/**/*.c)

OBJ := 	$(patsubst src/%.c, build/%.o, $(SRC))

.PHONY: all clean fclean

all: $(NAME)

re:	fclean all

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ) #$(LDFLAGS)

fclean:
	$(RM) build $(NAME) vgcore.*

build/%.o: src/%.c
	@mkdir -p $(shell dirname $@)
	$(CC) $(CFLAGS) -c $< -o $@
