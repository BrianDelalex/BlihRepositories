NAME	=	solver

CC	=	gcc -g3 $(CFLAGS)

RM	=	rm -f

SRC	=	main.c	\
		use_getline.c	\
		search_exit.c	\

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
