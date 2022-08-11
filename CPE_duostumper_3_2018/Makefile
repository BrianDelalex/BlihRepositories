NAME	=	mydb

CC	=	gcc -g3 $(CFLAGS)

RM	=	rm -f


SRC	=	add_movie_to_tab.c	\
		open_database.c	\
		use_getline.c	\
		main.c	\

SRCS	=	$(addprefix ./src/, $(SRC))

OBJS	=	$(SRCS:.c=.o)

LIB	=	-L./lib -lmy

CFLAGS = -I./include
CFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	make -C lib/
	$(CC) $(OBJS) -o $(NAME) $(LIB)

clean:
	$(RM) $(OBJS)

fclean: clean
	make -C lib/ fclean
	$(RM) $(NAME)

re: fclean all
