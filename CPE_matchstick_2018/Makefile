NAME	=	matchstick

CC	=	gcc -g3 $(CFLAGS)

RM	=	rm -f

LIB	=	-L./lib/ -lmy

SRC	=	main.c	\
		my_getnbr.c	\
		my_puterror.c	\
		handle_errors.c	\
		create_map.c	\
		free_values.c	\
		chose_turn.c	\
		catch_player_action.c	\
		my_strlen.c	\
		use_getline.c	\
		remove_char_from_str.c	\
		check_if_nb.c	\
		remove_match_ia.c	\
		get_last_char_str.c

SRCS	=	$(addprefix src/, $(SRC))

OBJS	=	$(SRCS:.c=.o)

CFLAGS 	=	-I./include
CFLAGS 	+=	-Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LIB)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
