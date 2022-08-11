##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

CC	=	gcc -g3

SRC	=	main_minishell.c		\
		cd_function.c		\
		environnement_function.c	\
		use_function.c		\
		setenv_function.c		\
		cd_funct_more.c		\
		check_command.c		\
		system_binary.c		\
		system_binary_more.c	\
		cd_options.c		\
		lib_project.c		\
		pipe_exec.c		\
		redirections.c		\
		main_loop.c		\
		redir_inf_exec.c	\
		echo_function.c	\
		cut_input_to_tab.c	\
		exec_and_redirect_in_file.c	\
		check_redirect_char.c	\
		exec_common.c	\
		exec_buffering_bin.c	\
		env_var_exist.c	\
		exec_with_modified_input.c	\
		exec_pipe.c	\
		exec_bin.c	\
		display_bin_error.c	\
		is_a_builtin.c	\
		set_control.c	\
		free_input_ressources.c	\
		initiate_env.c	\

SRCS	=	$(addprefix ./src/, $(SRC))

OBJ	=	$(SRCS:.c=.o)

NAME	=	42sh

LDFLAGS	=	-L./lib/my -lmy -g

CFLAGS	+=	-I include/ -g -Wall -Wextra

RM	=	rm -f

.PHONY: all clean re fclean my

all:	my	$(NAME)

$(NAME):	$(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LDFLAGS)

my:
	make -C lib/my

clean:
	$(RM) $(OBJ)
	make clean -C lib/my

fclean:	clean
	$(RM) $(NAME)
	rm -f vgcore.*
	make fclean -C lib/my
	rm -f *.gc* unit_test

re:	fclean all

tests_run:
	gcc -o unit_test tests/test_str_to_tab.c lib/my/str_to_tab.c lib/my/nbr_char_str.c --coverage -lcriterion
	./unit_test
