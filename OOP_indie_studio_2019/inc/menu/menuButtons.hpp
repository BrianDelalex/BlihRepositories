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

class menuButtons
{
    public:
        menuButtons(irr::video::IVideoDriver *driver, int buttonPurpose);
        irr::video::ITexture* getTexture();
        irr::s32 getButtonHeight();
        irr::s32 getButtonWidth();
        irr::s32 getButtonPosX();
        irr::s32 getButtonPosY();
        int getPurpose();
        ~menuButtons();
    private:
        irr::video::ITexture* buttonTexture;
        irr::s32 buttonHeight;
        irr::s32 buttonWidth;
        irr::s32 buttonPosX;
        irr::s32 buttonPosY;
        int buttonPurpose;
};