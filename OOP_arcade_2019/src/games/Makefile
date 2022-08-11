##
##
##
##
##

OBJECT_DIR	:=	build/games/errors

SOURCE_DIR	:=	errors/

SOURCE	:=	$(wildcard $(SOURCE_DIR)/*$(EXTENSION))

OBJECT	:=	$(patsubst $(SOURCE_DIR)/%$(EXTENSION), $(OBJECT_DIR)/%.o, $(SOURCE))

INCLUDE	:=	-I$(PROJECT_DIR)/inc/games/errors

all: $(OBJECT)
	@echo -e "Creating games/"
	@mkdir -p $(PROJECT_DIR)/games
	@echo -e "\tBUILDING pacman"
	@make --no-print-directory -C pacman
	@echo -e "\tBUILDING solarFox"
	@make --no-print-directory -C solarFox

clean:
	@echo -e "\tCLEANING pacman"
	@make --no-print-directory clean -C pacman
	@echo -e "\t CLEANING solarFox"
	@make --no-print-directory clean -C solarFox

fclean:
	@make --no-print-directory fclean -C pacman
	@make --no-print-directory fclean -C solarFox
	@$(RM) $(PROJECT_DIR)/games
	@echo -e "\tRM games"

re:
	@make --no-print-directory re -C pacman
	@make --no-print-directory re -C solarFox

$(OBJECT_DIR)/%.o:	$(SOURCE_DIR)/%$(EXTENSION)
	@mkdir -p $(shell dirname $(PROJECT_DIR)/$@)
	$(CXX) $(FLAGS) $(INCLUDE) -fPIC -c $< -o $(PROJECT_DIR)/$@
	@echo -e "\tCXX $@"