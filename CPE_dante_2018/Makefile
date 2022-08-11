NAME	=	test

CC	=	gcc -g3 $(CFLAGS)

RM	=	rm -f

SRC	=

SRCS	=	$(addprefix ./src/, $(SRC))

OBJS	=	$(SRCS:.c=.o)

LIB	=	-L./lib -lmy

CFLAGS = -I./include
CFLAGS += -Wall -Wextra

all:	$(NAME)

$(NAME):
	make -C ./solv/ re
	cp solv/solver ./
	make -C ./gen/ re
	cp gen/generator ./

clean:
	make -C ./solv/ clean
	make -C ./gen/ clean
	make -C ./lib/ clean

fclean: clean
	make -C lib/ fclean
	make -C ./solv/ fclean
	make -C ./gen/ fclean
	rm -f solver generator 

re: fclean all
