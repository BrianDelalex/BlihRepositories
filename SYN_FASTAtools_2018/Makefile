NAME	=	FASTAtools

CC	=	gcc -g3 $(CFLAGS)

RM	=	rm -f

SRC	=	main.c	\
		handle_error.c	\
		use_getline.c	\
		free_tab.c	\
		get_file.c	\
		remove_unwanted_char.c	\
		display_dna_seq.c	\
		save_dna.c	\
		reverse_complement.c	\
		my_revstr.c	\
		find_coding_seq.c	\
		separate_codon.c	\
		sort_in_alpha_order.c	\
		find_kmer.c	\
		choose_display.c	\
		find_amino_acids.c	\
		find_amino_acidsbis.c	\

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
