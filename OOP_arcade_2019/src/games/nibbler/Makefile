##
##
##
##
##

BIN	:=	games/lib_arcade_nibbler.so

FLAGS	:=	-Wall

SOURCE_DIR	:=	.

OBJECT_DIR	:=	/build/games/nibbler

SOURCE	:=	$(wildcard $(SOURCE_DIR)/*$(EXTENSION))

OBJECT	:=	$(patsubst $(SOURCE_DIR)/%$(EXTENSION), $(OBJECT_DIR)/%.o, $(SOURCE))

all:	$(BIN)

clean:
	@$(RM) $(PROJECT_DIR)$(OBJECT_DIR)
	@echo -e "\t\tRM $(OBJECT_DIR)"

fclean: clean
	@$(RM) $(PROJECT_DIR)/$(BIN)
	@echo -e "\t\tRM $(BIN)"

re:	fclean all

$(BIN):	$(OBJECT)
	@$(CXX) $(FLAGS) -shared $(addprefix $(PROJECT_DIR),$(OBJECT_DIR)/*.o) -o $(PROJECT_DIR)/$(BIN)
	@echo -e "\t\tCXX $(BIN)"

$(OBJECT_DIR)/%.o:	$(SOURCE_DIR)/%$(EXTENSION)
				@mkdir -p $(shell dirname $(addprefix $(PROJECT_DIR), $@))
				@$(CXX) $(FLAGS) -fPIC -c $< -o $(addprefix $(PROJECT_DIR), $@)
				@echo -e "\t\tCXX $@"