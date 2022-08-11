NAME	=	palindrome

CC	=	gcc -g3 $(CFLAGS)

RM	=	rm -f

SRC	=	main.c	\
		create_parse.c	\
		change_base_to_int.c	\
		change_base_to_char.c	\
		char_to_int.c	\
		find_palindrome.c	\
		my_revstr.c	\
		int_to_char.c	\
		handle_error.c	\

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
	$(RM) $(NAME) unit_test *.gc*

re: fclean all
