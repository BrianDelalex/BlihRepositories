##
##
##
##
##

export CC	:=	LD_LIBRARY_PATH=$(shell realpath .) gcc

export LDPREFIX	:=	

export FLAGS	:=	-Wall	\
			-Wextra	\
			-Wnested-externs	\
			-Winline			\
			-Wpragmas			\
			-std=gnu11			\
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
			-Wmissing-prototypes	\
			-Wstrict-prototypes	\
			-Wpointer-arith	\
			-luuid			\
			-lmyteams		\
			-L $(shell realpath ./libs/myteams)

export PROJECT_DIR	:=	$(shell realpath ./)

export RM	:=	@rm -rf

export INCLUDE	:=	-I$(PROJECT_DIR)/inc -I$(PROJECT_DIR)/libs

.PHONY: all server client

all: echo_build server client

echo_build:
	@echo -e "Building my_teams"

server:
	@echo -e "  make utils"
	@make --no-print-directory -s -C src/utils
	@echo -e "  make server"
	@make --no-print-directory -s -C src/server

client:
	@echo -e " make client"
	@make --no-print-directory -s -C src/client

fclean:
	@echo -e "fclean my_teams"
	@echo -e "  fclean server"
	@make --no-print-directory -s fclean -C src/server
	@echo -e "  fclean client"
	@make --no-print-directory -s fclean -C src/client
	@$(RM) build
	@echo -e "RM build/"

clean:
	@echo -e "clean my_teams"
	@echo -e "  clean server"
	@make --no-print-directory -s clean -C src/server
	@echo -e "  clean client"
	@make --no-print-directory -s clean -C src/client

re:
	@echo -e "make re my_teams"
	@echo -e "  make re server"
	@make --no-print-directory -s re -C src/server
	@echo -e "  make re client"
	@make --no-print-directory -s re -C src/client