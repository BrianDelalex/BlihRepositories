/*
** EPITECH PROJECT, 2019
** init.cpp
** File description:
** Initialisation of core
*/

#include "core.hpp"
#include <ios>

GraphicsManager *create_graphics_manager(char *av)
{
    GraphicsManager *gm = new GraphicsManager;

    try
    {
        gm->init(std::string(av));
    }
    catch(const GraphicsManagerError& e)
    {
        std::cerr << e.getComponent() << ":" << e.what() << '\n';
        delete gm;
        return (nullptr);
    }
    return (gm);
}

GameManager *create_games_manager()
{
    GameManager *gm = new GameManager;

    try
    {
        gm->init();
    }
    catch(const GameManagerError& e)
    {
        std::cerr << e.getComponent() << ":" << e.what() << '\n';
        delete gm;
        return (nullptr);
    }
    return (gm);
}

void initialisation_display(GraphicsManager *graphM, GameManager *gameM)
{
    std::vector<std::string> gameList = gameM->getGameList();
    std::vector<std::string> gameLibList = gameM->getLibList();
    std::vector<std::string> graphList = graphM->getLib();
    
    std::cout << "./games:\n";
    for (int i = 0; i < (int) gameList.size() && i < (int) gameLibList.size(); i++)
    {
        std::cout << gameLibList.at(i) << " --> " << gameList.at(i) << std::endl;
    }
    std::cout << std::endl;
    std::cout << "./lib:\n";
    for (int i = 0; i < (int) graphList.size(); i++)
    {
        std::cout << graphList.at(i) << std::endl;
    }
    std::cout << std::endl;
}

std::string prompt_name()
{
    std::string name;

    std::cout << "Enter your name: ";
    std::getline(std::cin, name);
    if (std::cin.eof()) {
        throw std::ios_base::failure("EOF catched");
    }
    return (name);
}

void init(char *av)
{
    GraphicsManager *graphM;
    GameManager *gameM;
    std::string name;

    if ( (graphM = create_graphics_manager(av)) == nullptr)
        exit(84);
    if ( (gameM = create_games_manager()) == nullptr)
    {
        delete graphM;
        exit(84);
    }
    initialisation_display(graphM, gameM);
    try
    {
        name = prompt_name();
    } catch (const std::ios_base::failure &e)
    {
        std::cout << e.what() << std::endl;
        delete gameM;
        delete graphM;
        exit(84);
    }
    std::string selectedGame = open_menu(graphM, gameM);
    std::cout << "SELECTED GAME: " << selectedGame << std::endl;
    arcd::render *rd;
    try
    {
        graphM->init_lib();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        delete graphM;
        delete gameM;
        exit(84);
    }
    try
    {
        gameM->load(selectedGame);
        rd = gameM->init_lib();
    }
    catch(const GameManagerError& e)
    {
        std::cerr << e.getComponent() << ": " << e.what() << '\n';
        delete graphM;
        delete gameM;
        exit(84);
    }
    
    loop(rd, graphM, gameM);
    delete graphM;
    delete gameM;
}