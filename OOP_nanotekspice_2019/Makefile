##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

CXX	:=	g++ -g3

FLAGS	:=	-Wall	\
			-Wextra	\

INCLUDE	:=	-I./inc	\
			$(addprefix -I./inc/,	\
								components/src/	\
								components/	\
								errors/		\
								display/	\
								interpreter	\
								parsing		\
											)

export INC	:=	$(shell realpath inc)

BIN := nanotekspice

EXTENSION	:=	.cpp

export OBJECTDIR	:=	$(shell realpath .)/build

SOURCEDIR	:=		src	\
					$(addprefix src/,	\
									interpreter	\
									interpreter/handler	\
									parsing		\
									display		\
									errors		\
									process		\
									)

COMPONENTSDIR	:=	$(shell realpath src)/components

COMPONENTSOBJDIR :=	src/components	\
					src/components/src

export OBJECTCOMPONENTS	:= $(patsubst $(COMPONENTSOBJDIR)/%$(EXTENSION), $(OBJECTDIR)/%.o ,$(wildcard $(addsuffix /*$(EXTENSION), $(COMPONENTSOBJDIR))))

SOURCE	:=	$(wildcard $(addsuffix /*$(EXTENSION), $(SOURCEDIR)))

OBJ :=	$(patsubst src/%$(EXTENSION), $(OBJECTDIR)/%.o, $(SOURCE))

RM :=	rm -rf

.PHONY:	fclean clean all

all:	$(BIN)

$(BIN):	$(OBJ)
			@make obj --no-print-directory -C $(COMPONENTSDIR)
			@echo $(OBJECTCOMPONENTS)
			@$(CXX) $(FLAGS) $(OBJ) $(OBJECTCOMPONENTS) $(INCLUDE) -o $(BIN) 
			@echo CXX $(patsubst $(PWD)/%, "/%", $(OBJ)) $(patsubst $(PWD)/%, %, $(OBJECTCOMPONENTS)) -o $(BIN)

clean:
	@$(RM) $(OBJECTDIR)

fclean:	clean
	@make fclean --no-print-directory -C $(COMPONENTSDIR)
	@$(RM) $(BIN)
	@echo CLEANED

re:	fclean all

$(OBJECTDIR)/%.o: src/%$(EXTENSION)
			@mkdir -p $(shell dirname $@)
			@$(CXX) $(FLAGS) $(INCLUDE) -c $< -o $@
			@echo -e "CXX $(patsubst $(PWD)/%,"/%",$@)"
