/*
** EPITECH PROJECT, 2019
** pacman.hpp
** File description:
** header file for pacman
*/

#ifndef PACMAN_HPP_
#define PACMAN_HPP_

#define MAP_DIR "/ressources/games/pacman/"
#define NOW std::chrono::high_resolution_clock::now()
#define TIMEPOINT std::chrono::high_resolution_clock::time_point
#define DURATION std::chrono::duration_cast
#define SECONDS std::chrono::seconds
#define MILLISECONDS std::chrono::milliseconds
#define is_a_wall(c) (c == '|' || c == '#' || c == '%')
#define is_a_door(c) (c == '%')

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <chrono>

#include "renderer.hpp"
#include "Player.hpp"
#include "Ghost.hpp"

void go_up(arcd::Ply *ply);
void go_down(arcd::Ply *ply);
void go_left(arcd::Ply *ply);
void go_right(arcd::Ply *ply);
bool can_go_up(arcd::Ply *ply, std::vector<std::string> *map, bool release);
bool can_go_down(arcd::Ply *ply, std::vector<std::string> *map, bool release);
bool can_go_left(arcd::Ply *ply, std::vector<std::string> *map, bool release);
bool can_go_right(arcd::Ply *ply, std::vector<std::string> *map, bool release);

#endif