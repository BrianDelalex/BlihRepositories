#
#
#
#
#

BIN	:=	lib/lib_arcade_ncurses.so

LIB	:=	-lncurses

INCLUDE :=	-I$(PROJECT_DIR)/inc/graphics/ncurses -I$(PROJECT_DIR)/inc/core

OBJECT_DIR	:=	build/graphics/ncurses

SOURCE_DIR	:=	./	\
				menu/

SOURCE	:=	$(wildcard $(addsuffix /*$(EXTENSION), $(SOURCE_DIR)))

OBJECT	:=	$(patsubst %$(EXTENSION), $(OBJECT_DIR)/%.o, $(SOURCE))

all:	debug	$(BIN)

debug:
	@echo -e "SOURCE: $(SOURCE)"

clean:
	$(RM) $(OBJECT_DIR)

fclean: clean
	$(RM) $(PROJECT_DIR)/$(BIN)

$(BIN):	$(OBJECT)
		@$(CXX) -shared $(FLAGS) $(INCLUDE) $(MACRO) $(addprefix $(PROJECT_DIR)/, $(OBJECT)) -o $(PROJECT_DIR)/$(BIN) $(LIB)
		@echo "HERE $(OBJECT)"
$(OBJECT_DIR)/%.o: %$(EXTENSION)
	@mkdir -p $(shell dirname $(addprefix $(PROJECT_DIR)/, $@))
	@$(CXX) $(FLAGS) $(INCLUDE) $(MACRO) -fPIC -c $< -o  $(addprefix $(PROJECT_DIR)/, $@) $(LIB)
	@echo -e "\t\tCXX $@"