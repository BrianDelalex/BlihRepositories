##
##
##
##
##

export PROJECT_DIR	:=	$(shell realpath ./)

export CXX	:=	g++ -g3

export EXTENSION :=	.cpp

LIB	:=	-ldl

BIN	:=	arcade

export RM	:=	rm -rf

export FLAGS	:=	-std=c++11 -Wall -Wextra

INCLUDE :=	-Iinc/core -Iinc/core/errors -Iinc/core/interfaces -Iinc/graphics -Iinc/utils

OBJECT_DIR	:=	build

SOURCE_DIR	:=	src/core	\
				src/utils	\
			$(addprefix src/core/, \
			errors)

SOURCE	:=	$(wildcard $(addsuffix /*$(EXTENSION), $(SOURCE_DIR)))

OBJECT	:=	$(patsubst $(SOURCE_DIR)/%$(EXTENSION), $(OBJECT_DIR)/%.o, $(SOURCE))

export MACRO	:=	'-D PROJECT_DIR="$(PROJECT_DIR)"'

all:	core graphics games

core:	$(BIN)

games:
	@echo -e "BUILDING games"
	@make --no-print-directory -C src/games

graphics:
	@echo -e "BUILDING graphics"
	@make --no-print-directory -C src/graphics


clean:
	@echo -e "CLEANING games"
	@make --no-print-directory clean -C src/games
	@echo -e "CLEANING graphics"
	@make --no-print-directory clean -C src/graphics
	@$(RM) $(OBJECT_DIR)
	@echo -e "RM $(OBJECT_DIR)"

fclean: clean
	@make --no-print-directory fclean -C src/games
	@make --no-print-directory fclean -C src/graphics
	@$(RM) $(BIN)
	@echo -e "RM $(BIN)"

re:
	make --no-print-directory re -C src/games
	make --no-print-directory re -C src/graphics

$(BIN): $(OBJECT)
	@echo -e "BUILDING core"
	@echo -e "OBJECT: $(OBJECT)"
	@$(CXX) $(FLAGS) $(INCLUDE) $(OBJECT) $(MACRO) -o $(BIN) $(LIB)

$(OBJECT_DIR)/%.o:	$(SOURCE_DIR)/%$(EXTENSION)
	@mkdir -p $(shell dirname $@)
	@$(CXX) $(FLAGS) $(INCLUDE) -c $< -o $@ $(LIB)
	@echo -e "CXX $@"
	