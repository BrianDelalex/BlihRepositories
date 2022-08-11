/*
** EPITECH PROJECT, 2019
** ComponentCreator.cpp
** File description:
** 
*/

#include "interpreter/interpreter.hpp"
#include <string.h>

char const *noargCommand[COMMAND_NUMBER] =
{
    "display",
    "simulate",
    "exit",
    "loop",
    "dump",
    NULL
};

void (*noargHandler[COMMAND_NUMBER])(void) =
{
    display_handler,
    simulate_handler,
    exit_handler,
    loop_handler,
    dump_handler,
    NULL
};

void handleCommand(std::string line)
{
    for (uint i = 0; noargHandler[i] != NULL; i++)
        if (!strcmp(line.c_str(), noargCommand[i]))
        {
            noargHandler[i]();
            return;
        }
    if (line.find('=') != std::string::npos)
        input_handler(line.substr(0, line.find_first_of('=')), line.substr(line.find_first_of('=') + 1));
    else
        std::cerr << ERR_INV_CMD << std::endl;
}

void interpreter_entry(void)
{
    std::string line;

    std::cout << PROMPT_MSG;
    while (std::getline(std::cin, line))
    {
        handleCommand(line);
        std::cout << PROMPT_MSG;
    }
    exit (0);
}