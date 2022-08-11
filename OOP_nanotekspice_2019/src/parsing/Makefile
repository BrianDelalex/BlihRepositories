##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Makefile
##

CXX	:=	g++

EXTENSION	:=	.cpp

BIN	:=	parsingTest

FLAGS	:=	-g3		\
			-Wall	\
			-Wextra	\

INCLUDE	:=	-I../../inc/parsing	\
			-I../../inc/errors

SOURCEDIR	:=	.

SOURCE	:=	$(wildcard *$(EXTENSION)) \
			../errors/*$(EXTENSION)

OBJECTDIR	:=	../../build/parsing

OBJECTPARSING	:=	$(patsubst %$(EXTENSION), $(OBJECTDIR)/%.o, $(SOURCE))

RM	:= rm -rf

all:	$(BIN)

clean:
	@$(RM) $(OBJECTDIR)

fclean:	clean
	@$(RM) $(BIN)

re:	fclean all

obj:	$(OBJECTPARSING)

$(BIN):	$(OBJECTPARSING)
	$(CXX) $(FLAGS) $(INCLUDE) $(OBJECTPARSING) -o $(BIN)

$(OBJECTDIR)/%.o:	$(SOURCEDIR)/%$(EXTENSION)
		@mkdir -p $(shell dirname $@)
		@$(CXX) $(FLAGS) $(INCLUDE) -c $< -o $@
		@echo -e "CXX $(patsubst $(PWD)/%,"/%",$@)"