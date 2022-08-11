/*
** EPITECH PROJECT, 2019
** open_menu.cpp
** File description:
** Opening the starting menu
*/

#include "core.hpp"

std::string open_menu(GraphicsManager *graphM, GameManager *gameM)
{
    std::string selectGame;
    try
    {
        selectGame = graphM->menu(gameM->getGameList());
    }
    catch(const GraphicsManagerError& e)
    {
        std::cerr << e.getComponent() << ":" << e.what() << '\n';
        delete graphM;
        delete gameM;
        exit (84);
    }
    return (selectGame);
}