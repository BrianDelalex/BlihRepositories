##
##
##
##
##

all:
	@echo -e "Creating lib/"
	@mkdir -p $(PROJECT_DIR)/lib
	@echo -e "\tBUILDING sfml"
	@make --no-print-directory -C sfml
	@echo -e "\tBUILDING ncurses"
	@make --no-print-directory -C ncurses
	@echo -e "\tBUILDING libcaca"
	@make --no-print-directory -C libcaca

clean:
	@echo -e "\tCLEANING sfml"
	@make --no-print-directory clean -C sfml
	@echo -e "\tCLEANING ncurses"
	@make --no-print-directory clean -C ncurses
	@echo -e "\tCLEANING libcaca"
	@make --no-print-directory clean -C libcaca

fclean:
	@make --no-print-directory fclean -C sfml
	@make --no-print-directory fclean -C ncurses
	@make --no-print-directory fclean -C libcaca
	@$(RM) $(PROJECT_DIR)/lib
	@echo -e "\tRM lib"

re:
	@make --no-print-directory re -C sfml