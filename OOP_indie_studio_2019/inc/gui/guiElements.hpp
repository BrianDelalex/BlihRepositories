/*
**
**
**
**
*/

#pragma once
#include <irrlicht/irrlicht.h>
#include "game_components/Player.hpp"
#include "game_components/playerRegistry.hpp"
#include <iostream>
#include <vector>
enum buffIndex
{
    BOMB,
    WALL,
    FIRE,
    SPEED
};
enum textIndex
{
    LIVES,
    KILLS
};

class guiElements
{
    public:
        guiElements(irr::video::IVideoDriver *driver, irr::gui::IGUIEnvironment *guienv);
        ~guiElements();
        void displayText(irr::gui::IGUIEnvironment *guienv);
        void displayLives(int lives, irr::video::IVideoDriver *driver, int player);
        void displayBuff(int buffIndex, irr::video::IVideoDriver *driver, irr::gui::IGUIEnvironment *guienv, int player, int buffcnt);
void displayAll(irr::video::IVideoDriver *driver, irr::gui::IGUIEnvironment *guienv, std::vector<Player *> *ply);
        void removeBuff(int buffIndex, irr::video::IVideoDriver *driver);
    private:
        std::vector<irr::gui::IGUIStaticText*> *guiTexts;
        std::vector<irr::video::ITexture*> *guiIcons;
        std::vector<irr::video::ITexture*> *guiLives;
        irr::gui::IGUIFont *font;
};