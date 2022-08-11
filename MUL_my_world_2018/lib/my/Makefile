##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## make_lib
##

SRC	=	circle_double_list.c	\
		puterror.c		\
		my_strcmp.c		\
		strconcat.c		\
		my_putchar.c		\
		nbr_char_str.c		\
		str_to_tab.c		\
		my_getnbr.c		\
		my_put_nbr.c		\
		my_putstr.c		\
		my_revstr.c		\
		my_strcpy.c		\
		my_strlen.c		\
		my_strstr.c		\
		my_put_tab.c		\
		my_printf.c		\
		add_types.c		\
		adding_to_types.c	\
		adding_for_types.c	\
		fill_in_pars.c		\
		switch_types.c		\
		int_to_char.c		\
		get_next_line.c		\
		len_tab.c		\
		long_to_char.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(OBJ)
	ar rc $(NAME) *.o

$(NAME):	$(OBJ)
	ar rc $(NAME) *.o

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
