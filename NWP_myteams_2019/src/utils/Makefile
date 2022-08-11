##
##
##
##
##

CXX	:=	gcc

EXT	:=	.c

SOURCE_PATH	:= .	\

OBJECT_PATH	:=	build/utils

SOURCE	:=	$(wildcard $(addprefix src/utils/ , $(addsuffix /*$(EXT), $(SOURCE_PATH))))

OBJECT	:=	$(patsubst %$(EXT), $(OBJECT_PATH)/%.o, $(SOURCE))

all: $(OBJECT)

clean:
	$(RM) $(OBJECT_PATH)
	@echo -e "    RM $(OBJECT_PATH)"

.PHONY:	all

fclean:	clean

re:	fclean all

$(OBJECT_PATH)/%.o:	%$(EXT)
		@mkdir -p $(shell dirname $(addprefix $(PROJECT_DIR)/, $@))
		@$(CXX) $(FLAGS) $(INCLUDE) -c $< -o $(addprefix $(PROJECT_DIR)/, $@)
		@echo -e "    CXX $@"