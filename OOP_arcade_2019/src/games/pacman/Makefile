##
##
##
##
##

BIN	:=	games/lib_arcade_pacman.so

FLAGS	:=	-Wall

SOURCE_DIR	:=	.

INCLUDE	:=	-I$(PROJECT_DIR)/inc/core/ -I$(PROJECT_DIR)/inc/games/pacman -I$(PROJECT_DIR)/inc/games/errors

OBJECT_DIR	:=	/build/games/pacman

SOURCE	:=	$(wildcard $(SOURCE_DIR)/*$(EXTENSION))

OBJECT	:=	$(patsubst $(SOURCE_DIR)/%$(EXTENSION), $(OBJECT_DIR)/%.o, $(SOURCE))

ERROR_OBJECT	:=	$(PROJECT_DIR)/build/games/errors/*.o

all:	$(BIN)

clean:
	@$(RM) $(PROJECT_DIR)$(OBJECT_DIR)
	@echo -e "\t\tRM $(OBJECT_DIR)"

fclean: clean
	@$(RM) $(PROJECT_DIR)/$(BIN)
	@echo -e "\t\tRM $(BIN)"

re:	fclean all

$(BIN):	$(OBJECT)
	@$(CXX) $(FLAGS) $(INCLUDE) $(MACRO) -shared $(addprefix $(PROJECT_DIR),$(OBJECT_DIR)/*.o) $(ERROR_OBJECT) -o $(PROJECT_DIR)/$(BIN)
	@echo -e "\t\tCXX $(BIN)"

$(OBJECT_DIR)/%.o:	$(SOURCE_DIR)/%$(EXTENSION)
				@mkdir -p $(shell dirname $(addprefix $(PROJECT_DIR), $@))
				@$(CXX) $(FLAGS) $(INCLUDE) $(MACRO) -fPIC -c $< -o $(addprefix $(PROJECT_DIR), $@)
				@echo -e "\t\tCXX $ $@"
