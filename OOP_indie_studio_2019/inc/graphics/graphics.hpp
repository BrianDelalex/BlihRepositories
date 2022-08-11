/*
** EPITECH PROJECT, 2019
** graphics.hpp
** File description:
** graphics header
*/

#ifndef GRAPHICS_HPP_
#define GRAPHICS_HPP_

# include <irrlicht.h>
# include <iostream>
# include <vector>
# include <list>

# include "graphics/MyEventReceiver.hpp"

enum NodeID
{
   COLLIDE = 1 << 0,
   EXPLODE = 1 << 1,
   PLAYER = 1 << 2,
   NOEXPLODE = 1 << 3,
   POWERUP = 1 << 4,
   BOMBUP = 1 << 5,
   SPEEDUP = 1 << 6,
   FIREUP = 1 << 7,
   WALLPASS = 1 << 8,
   GROUND = 1 << 9,
   ANIMATION = 1 << 10
};

using namespace irr;

typedef std::vector<scene::ISceneNode *> IMeshVec;

struct graph_handler_s
{
    IrrlichtDevice *device;
    video::IVideoDriver *driver;
    scene::ISceneManager* smgr;
    MyEventReceiver *evthdl;
    gui::IGUIEnvironment *gui;
};

typedef struct graph_handler_s graph_handler_t;

class Player;
class IA;

graph_handler_t *init_graphics(void);
IMeshVec *create_map(graph_handler_t *gr_hdl, irr::scene::IMesh *plan, \
int width, int height, std::vector<std::string> *map);
void draw_window(graph_handler_t *grhdl, std::vector<Player *> *ply, std::vector<IA *> *ias);

#endif