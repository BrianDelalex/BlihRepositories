##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

CC	:=	gcc -g3 #-coverage

NAME	:=	binary

LIBNAME := libmy_malloc.so

LDFLAGS	:=	-g

CFLAGS	+=	-I./inc/ -g -Wall -Wextra -Wpointer-arith

RM	:=	rm -rf

SRC := $(wildcard src/*.c src/**/*.c)

OBJ := 	$(patsubst src/%.c, build/%.o, $(SRC))

.PHONY: all clean fclean link

all: $(NAME)

re:	fclean all

$(NAME):	$(OBJ)
	make -C ./lib
	gcc -shared -o $(LIBNAME) $(OBJ) -L./lib -lmy

fclean:
	make fclean -C ./lib
	$(RM) build $(NAME) vgcore.* libmy_malloc.so
build/%.o: src/%.c
	@mkdir -p $(shell dirname $@)
	$(CC) $(CFLAGS) -fPIC -c $< -o $@

test: $(OBJ)
	make -C ./lib
	$(CC) $(CFLAGS) -c test/main.c -o build/main.o
	$(CC) -o $(NAME) $(OBJ) build/main.o $(LDFLAGS) -L./lib -lmy