/*
** EPITECH PROJECT, 2019
** my_sfml.hpp
** File description:
** sfml header
*/

#ifndef MY_SFML_HPP_
#define MY_SFML_HPP_

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "renderer.hpp"

#define TILE_WIDTH 27
#define TILE_HEIGHT 27

sf::RenderWindow *create_window(unsigned int width, unsigned int height, const std::string &name);
extern "C" std::string menu_display(std::vector<std::string> gameList);
std::vector<sf::Text *> draw_banners(sf::RenderWindow *wd, const std::vector<std::string> &gameList, sf::Font font);
void draw_map(std::vector<std::string> *map);
void draw_player(arcd::Ply *ply, std::vector<std::string> *map);
void init_texture(arcd::Ply *ply);
void draw_texts(std::vector<arcd::String> *texts);
void draw_ennemies(std::vector<arcd::Ply> *ennemies);


#endif