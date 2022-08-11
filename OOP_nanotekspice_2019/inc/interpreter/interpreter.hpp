/*
** EPITECH PROJECT, 2019
** 
** File description:
** 
*/

/* INCLUDES */
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <memory>
#include <tuple>
#include <algorithm>
#include <exception>

#include "components/IComponent.hpp"

extern std::vector<std::unique_ptr<nts::IComponent>> *comps;

void interpreter_entry(void) __attribute__((noreturn));
void handleCommand(std::string line);

/* HANDLERS */
void display_handler(void);
void simulate_handler(void);
void exit_handler(void);
void loop_handler(void);
void dump_handler(void);

void input_handler(std::string, std::string);

#define COMMAND_NUMBER 7

#define PROMPT_MSG     "> "

#define ERR_INV_CMD  "Invalid command"