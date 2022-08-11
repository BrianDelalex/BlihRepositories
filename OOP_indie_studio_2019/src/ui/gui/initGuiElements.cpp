/*
**
**
**
**
*/

#include "gui/guiElements.hpp"

guiElements::guiElements(irr::video::IVideoDriver *driver, irr::gui::IGUIEnvironment *guienv)
{
    std::string path = PROJECT_DIR;
    path.append("/assets/icons/");
    std::string fontpath = PROJECT_DIR;
    fontpath.append("/assets/fonts/bigfont.png");
    std::cout << "LOL FONT PATH OMGOMGOGMOGMGOMGO : " << fontpath << std::endl;
    std::vector<irr::video::ITexture*> *textures = new std::vector<irr::video::ITexture*>;
    textures->push_back(driver->getTexture(std::string(path + "iconbomb.png").c_str()));
    textures->push_back(driver->getTexture(std::string(path + "wall75.png").c_str()));
    textures->push_back(driver->getTexture(std::string(path + "fire75.png").c_str()));
    textures->push_back(driver->getTexture(std::string(path + "speed75.png").c_str()));
    this->guiIcons = textures;

    std::vector<irr::video::ITexture*> *lives = new std::vector<irr::video::ITexture*>;
    lives->push_back(driver->getTexture(std::string(path + "lives-0.png").c_str()));
    lives->push_back(driver->getTexture(std::string(path + "lives-1.png").c_str()));
    lives->push_back(driver->getTexture(std::string(path + "lives-2.png").c_str()));
    lives->push_back(driver->getTexture(std::string(path + "lives-3.png").c_str()));
    driver->makeColorKeyTexture(lives->at(0), irr::video::SColor(0,0,0,0));
    this->guiLives = lives;
    this->font = guienv->getFont(fontpath.c_str());
    std::cout << "HUD - Loaded " << std::endl;
}

guiElements::~guiElements() {}