##
##
##
##
##

BIN	:=	lib/lib_arcade_libcaca.so

FLAGS	:=	-Wall `pkg-config --libs --cflags caca`

INCLUDE	:=	-I/usr/include -I$(PROJECT_DIR)/inc/graphics/libcaca -I$(PROJECT_DIR)/inc/core

OBJECT_DIR	:=	/build/graphics/libcaca

SOURCE_DIR	:=	.	\
				menu/

SOURCE	:=	$(wildcard $(addsuffix /*$(EXTENSION), $(SOURCE_DIR)))

OBJECT	:=	$(patsubst %$(EXTENSION), $(OBJECT_DIR)/%.o, $(SOURCE))

all:	$(BIN)

clean:
	@$(RM) $(PROJECT_DIR)$(OBJECT_DIR)
	@echo -e "\t\tRM $(OBJECT_DIR)"

fclean:	clean
	@$(RM)	$(PROJECT_DIR)/$(BIN)
	@echo -e "\t\tRM $(BIN)"

re:	fclean all

$(BIN):	$(OBJECT)
		@$(CXX) $(FLAGS) $(INCLUDE) $(MACRO) -shared $(addprefix $(PROJECT_DIR), $(OBJECT)) -o $(PROJECT_DIR)/$(BIN) $(LIBRAIRIES)
		@echo -e "\t\tCXX $(BIN)"


$(OBJECT_DIR)/%.o:	%$(EXTENSION)
				@mkdir -p $(shell dirname $(addprefix $(PROJECT_DIR)/, $@))
				@$(CXX) $(FLAGS) $(INCLUDE) $(MACRO) -fPIC -c $< -o $(addprefix $(PROJECT_DIR), $@) $(LIBRAIRIES)
				@echo -e "\t\tCXX $@"