##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

CC	:=	gcc -g3

CFLAGS	:=	-Wall -Wextra -Wpointer-arith

INCLUDES	:=	-I./inc	\
				-I./inc/objdump	\
				-I./inc/nm

RM	:=	rm -rf

BINNM	:=	my_nm

BINOBJDUMP	:=	my_objdump

EXTENSION	:=	.c

SOURCEDIR	:=	src

OBJECTDIR	:=	build

BLUE_ST	:=	\033[0;34m

RED_ST	:=	\033[0;31m

GREEN_ST	:=	\033[0;32m

COLOR_END	:=	\033[0m

SOURCE	:=	$(wildcard $(SOURCEDIR)/*$(EXTENSION)) \
			$(wildcard $(SOURCEDIR)/**/*$(EXTENSION))

OBJECT	:= $(patsubst $(SOURCEDIR)/%$(EXTENSION), $(OBJECTDIR)/%.o, $(SOURCE))

.SECOND:

OBJ	=	$(wildcard $(OBJECTDIR)/*.o)

NMOBJECT	=	$(wildcard $(OBJECTDIR)/nm/*.o)

OBJDUMPOBJECT	=	$(wildcard $(OBJECTDIR)/objdump/*.o)

all: $(BINNM) $(BINOBJDUMP)

nm: $(BINNM)

objdump: $(BINOBJDUMP)

clean:
		@$(RM) build

fclean:	clean
		@$(RM) $(BINOBJDUMP) $(BINNM)
		@echo -e "$(RED_ST)CLEANED$(COLOR_END)"

re: fclean all

$(BINNM):	$(OBJECT) $(.SECOND)
	@$(CC) $(CFLAGS) $(OBJ) $(NMOBJECT) -o $(BINNM)
	@echo -e "$(BLUE_ST)CC$(COLOR_END) $(GREEN_ST)$(BINNM)$(COLOR_END)"

$(BINOBJDUMP):	$(OBJECT)
		@$(CC) $(CFLAGS) $(OBJ) $(OBJDUMPOBJECT) -o $(BINOBJDUMP)
		@echo -e "$(BLUE_ST)CC$(COLOR_END) $(GREEN_ST)$(BINOBJDUMP)$(COLOR_END)"

$(OBJECTDIR)/%.o:	$(SOURCEDIR)/%$(EXTENSION)
		@mkdir -p $(shell dirname $@)
		@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
		@echo -e "$(BLUE_ST)CC$(COLOR_END) $@"
