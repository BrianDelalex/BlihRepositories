/*
** EPITECH PROJECT, 2019
** draw_window.cpp
** File description:
** draw window and all component.
*/

#include "graphics/graphics.hpp"
#include "game_components/Player.hpp"
#include "game_components/IA.hpp"
#include "graphics/Animator.hpp"
#include "gui/guiElements.hpp"

extern std::list<Animator *> *animators;


void draw_window(graph_handler_t *grhdl, std::vector<Player *> *ply, std::vector<IA *> *ias)
{
    guiElements *guiel = new guiElements(grhdl->driver, grhdl->gui);
    grhdl->smgr->addCameraSceneNode(0, irr::core::vector3df(0, 25, -15), \
    irr::core::vector3df(0, 0, 0), GROUND);
    //grhdl->smgr->addCameraSceneNodeFPS(0, 100.0F, 0.1F);
    while (grhdl->device->run())
    {
        
        for (auto it = ply->begin(); it != ply->end(); it++)
            (*it)->update();
        for (auto it = ias->begin(); it != ias->end(); it++)
            (*it)->update();
        for (auto it = animators->begin(); it != animators->end(); it++)
            if ((*it)->update()) {
                delete *it;
                it = animators->erase(it);
            }

        grhdl->driver->beginScene(true, true, irr::video::SColor(255,100,101,140));
        
        grhdl->smgr->drawAll();
        guiel->displayAll(grhdl->driver, grhdl->gui, ply);
        grhdl->gui->drawAll();
        grhdl->driver->endScene();
    }
}