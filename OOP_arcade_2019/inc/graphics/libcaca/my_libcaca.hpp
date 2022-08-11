/*
** EPITECH PROJECT, 2019
** my_libcaca.hpp
** File description:
** libcaca header
*/

#ifndef MY_LIBCACA_HPP_
#define MY_LIBCACA_HPP_

#include "caca.h"
#include "renderer.hpp"
#include <tuple>
#include <fstream>

void draw_map(std::vector<std::string> *map);
void draw_player(arcd::Ply *ply);
void draw_ennemies(std::vector<arcd::Ply> *ennemies);
void draw_texts(std::vector<arcd::String> *texts);

#endif