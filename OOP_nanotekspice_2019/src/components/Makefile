##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

CXX	:=	g++ -g3

EXTENSION	:=	.cpp

BIN	:=	compTest

FLAGS	:=	-Wall	\
			-Wextra	\

INCLUDE	:=	-I$(INC)/components	\
			-I$(INC)/components/src	\
			-I$(INC)/errors

SOURCEDIR	:=	.	\
				src

SOURCE	:=	$(wildcard $(addsuffix /*$(EXTENSION), $(SOURCEDIR)))

OBJECTDIR	:=	$(OBJECTDIR)/components

OBJECTCOMPONENTS	:=	$(patsubst %$(EXTENSION), $(OBJECTDIR)/%.o, $(SOURCE))

RM	:= rm -rf

all:	$(OBJECTCOMPONENTS)

clean:
	@$(RM) $(OBJECTDIR)

fclean:	clean
	@$(RM) $(BIN)

re:	fclean all

obj:	$(OBJECTCOMPONENTS)

$(BIN):	$(OBJECTCOMPONENTS)
	$(CXX) $(FLAGS) $(INCLUDE) $(OBJECTCOMPONENTS) -o $(BIN)

$(OBJECTDIR)/%.o:	%$(EXTENSION)
		@mkdir -p $(shell dirname $@)
		@$(CXX) $(FLAGS) $(INCLUDE) -c $< -o $@
		@echo -e "CXX $(patsubst $(PWD)/%,"/%",$@)"