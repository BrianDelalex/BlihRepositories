/*
** EPITECH PROJECT, 2019
** solarFox.hpp
** File description:
** solarFox header
*/

#ifndef SOLARFOX_HPP_
#define SOLARFOX_HPP_

#include "renderer.hpp"
#include "MapInitError.hpp"

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <chrono>

#define NOW std::chrono::high_resolution_clock::now()
#define TIMEPOINT std::chrono::high_resolution_clock::time_point
#define DURATION std::chrono::duration_cast
#define SECONDS std::chrono::seconds
#define MILLISECONDS std::chrono::milliseconds
#define IS_A_WALL(c) (c == '#')
#define IS_AN_ENNEMY(c) (c == '!')

#include "solarFox/Player.hpp"

void init_map();
extern "C" arcd::render *init();
void set_position();
void add_player(uint i, uint j);
void add_ennemie(uint i, uint j);
extern "C" arcd::render *update(uint key);

#endif