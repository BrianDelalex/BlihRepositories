/*
** EPITECH PROJECT, 2019
** core.hpp
** File description:
** Core includes and prototypes
*/

#ifndef CORE_HPP_
#define CORE_HPP_

#include <iostream>
#include <fstream>

/* BUILT-IN */
#include "GameManager.hpp"
#include "GameManagerError.hpp"
#include "GraphicsManager.hpp"
#include "GraphicsManagerError.hpp"
#include "graphics.hpp"

void handle_errors(int ac);
std::string open_menu(GraphicsManager *graphM, GameManager *gameM);
void init(char *av);
void loop(arcd::render *rd, GraphicsManager *graphM, GameManager *gameM);

#endif