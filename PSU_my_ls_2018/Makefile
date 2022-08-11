NAME	=	my_ls

CC	=	gcc -g3

RM	=	rm -f

SRC	=	main.c	\
		my_puterror.c	\
		parsing.c	\
		handle_recursive_flag.c	\
		add_char_to_tab.c	\
		my_strconcat.c	\
		my_strlen.c	\
		display_no_flags.c	\
		my_putstr.c	\
		remove_str_to_tab.c	\
		sort_tab_in_alpha_order.c	\
		my_charcapital.c	\
		remove_char_from_str.c	\
		get_last_char_str.c	\
		handle_list_flag.c	\
		my_strstr.c	\
		get_file_size.c	\
		get_file_user.c	\
		find_length.c	\
		get_mode.c	\
		get_total.c

SRCS	=	$(addprefix ./src/, $(SRC))

OBJS	=	$(SRCS:.c=.o)

CFLAGS	=	-I./include 
CFLAGS	+=	-Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) $(CFLAGS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
