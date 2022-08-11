/*
** EPITECH PROJECT, 2019
** init_graphics.cpp
** File description:
** init graphics components
*/

#include "graphics/graphics.hpp"

graph_handler_t *init_graphics()
{
    graph_handler_t *grhld = new graph_handler_t;

    grhld->evthdl = new MyEventReceiver;
    grhld->device = createDevice(video::EDT_OPENGL, \
    core::dimension2d<u32>(1920, 1080), 16, false, false, false, grhld->evthdl);
    grhld->driver = grhld->device->getVideoDriver();
    grhld->smgr = grhld->device->getSceneManager();
    grhld->gui = grhld->device->getGUIEnvironment();
    return (grhld);
}