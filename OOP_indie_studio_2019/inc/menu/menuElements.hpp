/*
**
**
**
**
*/

#pragma once
#include <irrlicht/irrlicht.h>
#include "graphics/graphics.hpp"
#include "menu/menuButtons.hpp"
#include <iostream>
#include <vector>

enum buffIndex
{
    SINGLE,
    TP,
    THP,
    FP,
    OPTIONS,
    EXIT
};

class menuElements
{
    public:
    menuElements(graph_handler_s *graphhdl);
    void drawMenu();
    int updateMenu();
    int startGame(int playercount);
    void initScene();
    ~menuElements();
    private:
    std::vector<menuButtons*> * mButtons;
    irr::video::ITexture* menuBackground;
    irr::s32 winWidth;
    irr::s32 winHeight;
    graph_handler_s *grhdl;
    bool gameStarted;
};