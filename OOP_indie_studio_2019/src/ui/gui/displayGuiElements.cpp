/*
**
**
**
**
*/
#include <string.h>
#include "gui/guiElements.hpp"


void guiElements::displayAll(irr::video::IVideoDriver *driver, irr::gui::IGUIEnvironment *guienv, std::vector<Player *> *players)
{
    guienv->getSkin()->setFont(this->font);
    buffs_t *buffs;
    guienv->clear();
    for (auto it = players->begin(); it != players->end(); it++) {
        buffs = (*it)->get_buffs();
        if (buffs->bomb > 0)
            this->displayBuff(BOMB, driver, guienv, (int)(*it)->get_id()+1, (int)buffs->bomb);
        if (buffs->speed > 0)
            this->displayBuff(SPEED, driver, guienv, (int)(*it)->get_id()+1, (int)buffs->speed);
        if (buffs->spread > 0)
            this->displayBuff(FIRE, driver, guienv, (int)(*it)->get_id()+1, (int)buffs->spread);
        if (buffs->wallpass > 0)
            this->displayBuff(WALL, driver, guienv, (int)(*it)->get_id()+1, (int)buffs->wallpass);
        this->displayLives(buffs->lives, driver, (int)(*it)->get_id()+1);
    }
}


void guiElements::displayText(irr::gui::IGUIEnvironment *guienv)
{
    this->guiTexts->at(LIVES)->setOverrideFont(this->font);
    this->guiTexts->at(KILLS)->setOverrideFont(this->font);
    guienv->drawAll();
}

void guiElements::displayLives(int lives, irr::video::IVideoDriver *driver, int player)
{
    switch (player) {
        case 1:
            driver->draw2DImage(this->guiLives->at(lives),
                                irr::core::vector2di(10, 10), 
                                irr::core::rect<irr::s32>(0,0,400,150));
            break;
        case 2:
            driver->draw2DImage(this->guiLives->at(lives),
                                irr::core::vector2di(1920 - 410 ,10), 
                                irr::core::rect<irr::s32>(0,0,400,150));
            break;
        case 3:
            driver->draw2DImage(this->guiLives->at(lives),
                                irr::core::vector2di(10, 1080 - 260), 
                                irr::core::rect<irr::s32>(0,0,400,150));
            break;
        case 4:
            driver->draw2DImage(this->guiLives->at(lives),
                                irr::core::vector2di(1920 - 410, 1080 - 260), 
                                irr::core::rect<irr::s32>(0,0,400,150));
            break;
        default:
            break;
    }
}


void guiElements::displayBuff(int buffIndex, irr::video::IVideoDriver *driver, irr::gui::IGUIEnvironment *guienv, int player, int buffcnt)
{
    irr::gui::IGUIStaticText* text;

    int x = 0;
    int y = 0;
    wchar_t buff[10];
    swprintf(buff, 10, L"%d", buffcnt);
    switch (buffIndex) {
        case BOMB:
            x = 10;
            y = 170;
            break;
        case WALL:
            x = 10 + 80;
            y = 170;
            break;
        case FIRE:
            x = 10 + (80 * 2);
            y = 170;
            break;
        case SPEED:
            x = 10 + (80 * 3);
            y = 170;
            break;
        default:
            break;
    }
    switch (player) {
        case 1:
            driver->draw2DImage(this->guiIcons->at(buffIndex),
                                irr::core::vector2di(x,y), 
                                irr::core::rect<irr::s32>(0,0,75,75));
            text = guienv->addStaticText(buff, irr::core::rect<irr::s32>(x,y,1920,1080), false, false);
            text->setOverrideFont(this->font);
            text->setOverrideColor(irr::video::SColor(255,255,255,255));
            break;
        case 2:
            driver->draw2DImage(this->guiIcons->at(buffIndex),
                                irr::core::vector2di((1920 - x) - 75,y), 
                                irr::core::rect<irr::s32>(0,0,75,75));
            text = guienv->addStaticText(buff, irr::core::rect<irr::s32>((1920 - x) - 75,y,1920,1080), false, false);
            text->setOverrideFont(this->font);
            text->setOverrideColor(irr::video::SColor(255,255,255,255));
            break;
        case 3:
            driver->draw2DImage(this->guiIcons->at(buffIndex),
                                irr::core::vector2di(x, (1080 - y) - 170), 
                                irr::core::rect<irr::s32>(0,0,75,75));
            text = guienv->addStaticText(buff, irr::core::rect<irr::s32>(x, (1080 - y) - 170,1920,1080), false, false);
            text->setOverrideColor(irr::video::SColor(255,255,255,255));
            text->setOverrideFont(this->font);
            break;
        case 4:
            driver->draw2DImage(this->guiIcons->at(buffIndex),
                                irr::core::vector2di((1920 - x) - 75, (1080 - y) - 170), 
                                irr::core::rect<irr::s32>(0,0,75,75));
            text = guienv->addStaticText(buff, irr::core::rect<irr::s32>((1920 - x) - 75, (1080 - y) - 170,1920,1080), false, false);
            text->setOverrideColor(irr::video::SColor(255,255,255,255));
            text->setOverrideFont(this->font);
            break;
        default:
            break;
    }
    guienv->drawAll();
}