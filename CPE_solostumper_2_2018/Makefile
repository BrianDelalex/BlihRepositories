NAME	=	anagram

CC	=	gcc -g3

RM	=	rm -f

SRC	=	main.c	\
		handle_errors.c	\
		my_puterror.c	\
		my_putstr.c	\
		my_strcapital.c	\
		my_strlen.c

SRCS	=	$(addprefix ./src/, $(SRC))

OBJS	=	$(SRCS:.c=.o)

CFLAGS = -I./include
CFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
