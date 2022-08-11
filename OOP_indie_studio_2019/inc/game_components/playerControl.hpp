/*
** EPITECH PROJECT, 2019
** playerControl.hpp
** File description:
** player control header
*/

#ifndef PLAYER_CONTROL_HPP_
#define PLAYER_CONTROL_HPP_

#include <Keycodes.h>

struct playerControl_s
{
    irr::EKEY_CODE _up;
    irr::EKEY_CODE _down;
    irr::EKEY_CODE _right;
    irr::EKEY_CODE _left;
    irr::EKEY_CODE _bomb;
};

static inline struct playerControl_s playerControl_create(irr::EKEY_CODE up, \
irr::EKEY_CODE down, irr::EKEY_CODE right, irr::EKEY_CODE left, \
irr::EKEY_CODE bomb)
{
    struct playerControl_s control;

    control._up = up;
    control._down = down;
    control._right = right;
    control._left = left;
    control._bomb = bomb;
    return (control);
}

#endif