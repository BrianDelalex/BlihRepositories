##
##
##
##
##

BIN	:=	groundhog

CXX	:=	g++

FLAGS	:=	-Wall \
			-Wextra	\
			-Wextra	\
			-Werror	\
			-Winline			\
			-Wpragmas			\
			-Wuninitialized		\
			-Wno-missing-braces	\
			-Wcast-align		\
			-Wwrite-strings		\
			-Wparentheses		\
			-Wunreachable-code	\
			-Wunused			\
			-Wmissing-field-initializers	\
			-Wswitch-enum		\
			-Wshadow			\
			-Wuninitialized		\
			-Wmissing-declarations	\
			-Wpointer-arith	\

INCLUDE	:=	-Iinc

RM	:=	@rm -rf

EXT	:=	.cpp

SOURCE_PATH	:=	./src

OBJECT_PATH	:=	build

SOURCE	:=	$(wildcard $(SOURCE_PATH)/*$(EXT))

OBJECT	:=	$(patsubst $(SOURCE_PATH)/%$(EXT), $(OBJECT_PATH)/%.o, $(SOURCE))

all:	$(BIN)

clean:
	$(RM) $(OBJECT_PATH)
	@echo -e "RM $(OBJECT_PATH)"

fclean:	clean
	$(RM) $(BIN)
	@echo -e "RM $(BIN)"

re:	fclean all

$(BIN):	$(OBJECT)
	@$(CXX) $(FLAGS) $(INCLUDE) $(OBJECT_PATH)/*.o -o $(BIN)
	@echo -e "CXX $(BIN)"

$(OBJECT_PATH)/%.o:	$(SOURCE_PATH)/%$(EXT)
		@mkdir -p $(shell dirname $@)
		@$(CXX) $(FLAGS) $(INCLUDE) -c $< -o $@
		@echo -e "CXX $@"