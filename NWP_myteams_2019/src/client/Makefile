##
##
##
##
##

BIN	:=	myteams_cli

CXX	:=	gcc

EXT	:=	.c

SOURCE_PATH	:= .	\
			   commands	\
			   interpreter	\
			   network	\
			   errors	\

OBJECT_PATH	:=	build/client

SOURCE	:=	$(wildcard  $(addsuffix /*$(EXT), $(SOURCE_PATH)))

OBJECT	:=	$(patsubst %$(EXT), $(OBJECT_PATH)/%.o, $(SOURCE))

OBJ_PATH	:=	$(addprefix $(PROJECT_DIR)/build/client/, \
				$(SOURCE_PATH)	\
				) \
				$(PROJECT_DIR)/build/utils

.PHONY: $(OBJ)

.extension:
OBJ		= $(wildcard $(addsuffix /*.o, $(OBJ_PATH)))

all: $(BIN)

clean:
	$(RM) $(OBJECT_PATH)
	@echo -e "    RM $(OBJECT_PATH)"

fclean:	clean
	$(RM) $(PROJECT_DIR)/$(BIN)
	@echo -e "    RM $(BIN)"

re:	fclean all

$(BIN):	$(OBJECT) .extension
	@$(LDPREFIX) $(CXX) $(FLAGS) $(INCLUDE) $(OBJ) -o $(PROJECT_DIR)/$(BIN)
	@echo -e "    CXX $(BIN)"

$(OBJECT_PATH)/%.o:	%$(EXT)
		@mkdir -p $(shell dirname $(addprefix $(PROJECT_DIR)/, $@))
		@$(CXX) $(FLAGS) $(INCLUDE) -c $< -o $(addprefix $(PROJECT_DIR)/, $@)
		@echo -e "    CXX $@"