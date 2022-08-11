NAME	=	SBMLparser

CC	=	gcc -g3 $(CFLAGS)

RM	=	rm -f

SRC	=	main.c	\
		read_sbml_file.c	\
		use_getline.c	\
		sort_in_alpha_order.c	\
		create_list.c	\
		display_list.c	\
		create_parse.c	\
		read_with_i_flag.c	\
		create_iflag.c	\
		read_and_return_file.c	\
		display_compartment_tag.c	\
		add_int_list_to_tab.c	\
		display_species_tag.c	\
		find_reaction_name.c	\
		display_reaction_tag.c	\
		display_all_product.c	\
		handle_json_flag.c	\
		display_json_react.c	\
		load_json_species.c	\
		load_json_reaction.c	\
		load_json_compartment.c \
		display_json_species.c	\
		display_json_comp.c	\

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
	$(RM) $(NAME) unit_test *.gc* vgcore.*

re: fclean all
