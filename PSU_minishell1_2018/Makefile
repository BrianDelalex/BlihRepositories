NAME	=	mysh

CC	=	gcc -g3 $(CFLAGS)

RM	=	rm -f

SRC	=	main.c	\
		find_function.c	\
		set_control.c	\
		use_getline.c	\
		exec_cd.c	\
		free_values.c	\
		exec_exit.c	\
		exec_bin.c	\
		go_root.c

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

tests_run:
	gcc -o unit_test tests/test_my_str_to_tab.c lib/src/my_str_to_tab.c --coverage -lcriterion
	./unit_test
