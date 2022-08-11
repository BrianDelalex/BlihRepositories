/*
**
**
**
**
*/

#include "menu/menuElements.hpp"
#include "platform.hpp"
#include "graphics/graphics.hpp"
#include "game_components/Map.hpp"
#include "game_components/Player.hpp"
#include "game_components/IA.hpp"
#include "game_components/playerRegistry.hpp"
#include "game_components/playerControl.hpp"
#include "graphics/Animator.hpp"
#include "menu/menuElements.hpp"
extern struct playerRegistry_s *registry;
extern std::list<Animator *> *animators;
menuElements::menuElements(graph_handler_s *graphhdl)
{
    this->grhdl = graphhdl;
    std::string buttonPath = PROJECT_DIR;
    const irr::core::dimension2du size = grhdl->driver->getScreenSize();
    buttonPath.append("assets/buttons/");
    this->winHeight = size.Height;
    this->winWidth = size.Width;
    this->menuBackground = grhdl->driver->getTexture(std::string(buttonPath + "bg.png").c_str());
    this->mButtons = new std::vector<menuButtons*>;
    this->mButtons->push_back(new menuButtons(grhdl->driver, SINGLE));
    this->mButtons->push_back(new menuButtons(grhdl->driver, TP));
    this->mButtons->push_back(new menuButtons(grhdl->driver, THP));
    this->mButtons->push_back(new menuButtons(grhdl->driver, FP));
    this->mButtons->push_back(new menuButtons(grhdl->driver, OPTIONS));
    this->mButtons->push_back(new menuButtons(grhdl->driver, EXIT));
}

void menuElements::drawMenu()
{
    grhdl->driver->draw2DImage(mButtons->at(SINGLE)->getTexture(),
                        irr::core::vector2di(this->mButtons->at(SINGLE)->getButtonPosX(),
                                             this->mButtons->at(SINGLE)->getButtonPosY()),
                        irr::core::rect<irr::s32>(0,
                                                  0,
                                                  this->mButtons->at(SINGLE)->getButtonWidth(),
                                                  this->mButtons->at(SINGLE)->getButtonHeight())
                        );
    grhdl->driver->draw2DImage(mButtons->at(TP)->getTexture(),
                        irr::core::vector2di(this->mButtons->at(TP)->getButtonPosX(),
                                             this->mButtons->at(TP)->getButtonPosY()),
                        irr::core::rect<irr::s32>(0,
                                                  0,
                                                  this->mButtons->at(TP)->getButtonWidth(),
                                                  this->mButtons->at(TP)->getButtonHeight())
                        );
    grhdl->driver->draw2DImage(mButtons->at(THP)->getTexture(),
                        irr::core::vector2di(this->mButtons->at(THP)->getButtonPosX(),
                                             this->mButtons->at(THP)->getButtonPosY()),
                        irr::core::rect<irr::s32>(0,
                                                  0,
                                                  this->mButtons->at(THP)->getButtonWidth(),
                                                  this->mButtons->at(THP)->getButtonHeight())
                        );
    grhdl->driver->draw2DImage(mButtons->at(FP)->getTexture(),
                        irr::core::vector2di(this->mButtons->at(FP)->getButtonPosX(),
                                             this->mButtons->at(FP)->getButtonPosY()),
                        irr::core::rect<irr::s32>(0,
                                                  0,
                                                  this->mButtons->at(FP)->getButtonWidth(),
                                                  this->mButtons->at(FP)->getButtonHeight())
                        );
    grhdl->driver->draw2DImage(mButtons->at(OPTIONS)->getTexture(),
                        irr::core::vector2di(this->mButtons->at(OPTIONS)->getButtonPosX(),
                                             this->mButtons->at(OPTIONS)->getButtonPosY()),
                        irr::core::rect<irr::s32>(0,
                                                  0,
                                                  this->mButtons->at(OPTIONS)->getButtonWidth(),
                                                  this->mButtons->at(OPTIONS)->getButtonHeight())
                        );
    grhdl->driver->draw2DImage(mButtons->at(EXIT)->getTexture(),
                        irr::core::vector2di(this->mButtons->at(EXIT)->getButtonPosX(),
                                             this->mButtons->at(EXIT)->getButtonPosY()),
                        irr::core::rect<irr::s32>(0,
                                                  0,
                                                  this->mButtons->at(EXIT)->getButtonWidth(),
                                                  this->mButtons->at(EXIT)->getButtonHeight())
                        );
}

int menuElements::updateMenu()
{
    irr::core::vector2di clicpos;
    if (grhdl->evthdl->IsLeftKeyDown() != true)
        return 0;
    clicpos = grhdl->evthdl->getMousePos();
    irr::core::vector2di test;
    test.X = mButtons->at(SINGLE)->getButtonPosX();
    test.Y = mButtons->at(SINGLE)->getButtonPosY();
    if ((clicpos.Y >= test.Y && clicpos.Y <= test.Y + mButtons->at(SINGLE)->getButtonHeight())
        && (clicpos.X >= test.X && clicpos.X <= test.X + mButtons->at(SINGLE)->getButtonWidth()))
        return (startGame(1));

    test.X = mButtons->at(TP)->getButtonPosX();
    test.Y = mButtons->at(TP)->getButtonPosY();
    if ((clicpos.Y >= test.Y && clicpos.Y <= test.Y + mButtons->at(TP)->getButtonHeight())
        && (clicpos.X >= test.X && clicpos.X <= test.X + mButtons->at(TP)->getButtonWidth()))
        return (startGame(2));

    test.X = mButtons->at(THP)->getButtonPosX();
    test.Y = mButtons->at(THP)->getButtonPosY();
    if ((clicpos.Y >= test.Y && clicpos.Y <= test.Y + mButtons->at(THP)->getButtonHeight())
        && (clicpos.X >= test.X && clicpos.X <= test.X + mButtons->at(THP)->getButtonWidth()))
        return (startGame(3));

    test.X = mButtons->at(FP)->getButtonPosX();
    test.Y = mButtons->at(FP)->getButtonPosY();
    if ((clicpos.Y >= test.Y && clicpos.Y <= test.Y + mButtons->at(FP)->getButtonHeight())
        && (clicpos.X >= test.X && clicpos.X <= test.X + mButtons->at(FP)->getButtonWidth()))
        return (startGame(4));

    test.X = mButtons->at(OPTIONS)->getButtonPosX();
    test.Y = mButtons->at(OPTIONS)->getButtonPosY();
    if ((clicpos.Y >= test.Y && clicpos.Y <= test.Y + mButtons->at(OPTIONS)->getButtonHeight())
        && (clicpos.X >= test.X && clicpos.X <= test.X + mButtons->at(OPTIONS)->getButtonWidth())) {
        std::cout << "Entering options" << std::endl;
        return (0);
    }

    test.X = mButtons->at(EXIT)->getButtonPosX();
    test.Y = mButtons->at(EXIT)->getButtonPosY();
    if ((clicpos.Y >= test.Y && clicpos.Y <= test.Y + mButtons->at(EXIT)->getButtonHeight())
        && (clicpos.X >= test.X && clicpos.X <= test.X + mButtons->at(EXIT)->getButtonWidth())) {
        grhdl->device->closeDevice();
        return (0);
        exit (0);
    }
    return (0);
}

int menuElements::startGame(int playercount)
{
    if (gameStarted != true) {
        gameStarted = true;
        std::string map_path = PROJECT_DIR;
        graph_handler_t *grhdl2 = init_graphics();
        Map *map;
        std::string meshPath = PROJECT_DIR;
        std::string textPath = PROJECT_DIR;
        std::string text2Path = PROJECT_DIR;
        animators = new std::list<Animator *>;
        std::srand(time(NULL));
        registry = playerRegistry_init();
        map_path.append("/assets/maps/map.txt");
        map = new Map(grhdl2, map_path, 15, 15);
        std::vector<Player *> *ply = create_player(playercount, grhdl2, map);
        std::vector<IA *> *ias = create_IA(playercount, 4 - playercount, grhdl2, map);
        this->grhdl->driver->drop();
        draw_window(grhdl2, ply, ias);
        std::cout << "Started a " << playercount << " player(s) game" << std::endl;
        return (1);
    } else
        std::cout << "A game is already running!" << std::endl;
        return (0);
    
}

void menuElements::initScene()
{
    grhdl->smgr->addCameraSceneNode(0, irr::core::vector3df(0, 25, -15), \
    irr::core::vector3df(0, 0, 0));
    while (grhdl->device->run()) 
    {
        grhdl->driver->beginScene(true, true, irr::video::SColor(255,100,101,140));
        this->drawMenu();
        if (this->updateMenu() == 1) {
            grhdl->driver->endScene();
            this-grhdl->device->drop();
            break;
        }
        grhdl->driver->endScene();
    }

}