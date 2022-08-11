/*
**
**
**
**
*/

#include "menu/menuElements.hpp"
#include "menu/menuButtons.hpp"

menuButtons::menuButtons(irr::video::IVideoDriver *driver, int buttonPurpose)
{
    const irr::core::dimension2du size = driver->getScreenSize();
    std::string path = PROJECT_DIR;
    path.append("/assets/buttons/");
    this->buttonPurpose = buttonPurpose;
    this->buttonWidth = 400;
    this->buttonHeight = 133;
    switch (buttonPurpose) {
        case SINGLE:
            this->buttonTexture = driver->getTexture(std::string(path + "singleplayer.png").c_str());
            this->buttonPosX = (size.Width / 2) - (400 / 2);
            this->buttonPosY = (size.Height / 3) - (133 / 2);
            break;
        case TP:
            this->buttonTexture = driver->getTexture(std::string(path + "2players.png").c_str());
            this->buttonPosX = (size.Width / 2) - (400 / 2) - 413;
            this->buttonPosY = ((size.Height / 3) - (133 / 2)) + 143;
            break;
        case THP:
            this->buttonTexture = driver->getTexture(std::string(path + "3players.png").c_str());
            this->buttonPosX = (size.Width / 2) - (400 / 2);
            this->buttonPosY = ((size.Height / 3) - (133 / 2)) + 143;
            break;
        case FP:
            this->buttonTexture = driver->getTexture(std::string(path + "4players.png").c_str());
            this->buttonPosX = (size.Width / 2) - (400 / 2) + 413;
            this->buttonPosY = ((size.Height / 3) - (133 / 2)) + 143;
            break;
        case OPTIONS:
            this->buttonTexture = driver->getTexture(std::string(path + "options.png").c_str());
            this->buttonPosX = (size.Width / 2) - (400 / 2);
            this->buttonPosY = (size.Height / 3) - (133 / 2);
            break;
        case EXIT:
            this->buttonTexture = driver->getTexture(std::string(path + "exit.png").c_str());
            this->buttonPosX = (size.Width / 2) - (400 / 2);
            this->buttonPosY = ((size.Height / 3) - (133 / 2)) + 143 * 3;
            break;
    };
    
}

irr::video::ITexture* menuButtons::getTexture()
{
    return (this->buttonTexture);
}

int menuButtons::getPurpose()
{
    return (this->buttonPurpose);
}

irr::s32 menuButtons::getButtonHeight()
{
    return (this->buttonHeight);
}

irr::s32 menuButtons::getButtonWidth()
{
    return (this->buttonWidth);
}

irr::s32 menuButtons::getButtonPosX()
{
    return (this->buttonPosX);
}

irr::s32 menuButtons::getButtonPosY()
{
    return (this->buttonPosY);
}