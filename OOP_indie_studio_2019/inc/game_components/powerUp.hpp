#ifndef POWERUP_HPP_
#define POWERUP_HPP_

# include "graphics/graphics.hpp"

enum POWER_UP
{
    BombUp,
    SpeedUp,
    FireUp,
    WallPass,
    ANY
};

void create_powerup(graph_handler_t *grhdl, POWER_UP power, core::vector3df pos);

#endif
