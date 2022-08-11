/*
** EPITECH PROJECT, 2019
** draw_map.cpp
** File description:
** draw map in sfml mod
*/

#include "my_sfml.hpp"

extern sf::RenderWindow *wd;
int mapX;
int mapY;

void draw_texts(std::vector<arcd::String> *texts)
{
    std::string font_path = PROJECT_DIR;
    font_path.append("/ressources/graphics/sfml/FiraCode-Bold.ttf");
    sf::Font font;
    font.loadFromFile(font_path);
    for (uint i = 0; i < texts->size(); i++)
    {
        sf::Text text((*texts)[i].str, font, (*texts)[i].size);
        text.setPosition({((float) mapX + (*texts)[i].pos.x * TILE_WIDTH), ((float)mapY + (*texts)[i].pos.y * TILE_HEIGHT)});
        wd->draw(text);
    }
}

sf::RectangleShape load_wall()
{
    sf::Vector2f size = {TILE_WIDTH, TILE_HEIGHT};
    sf::RectangleShape rect(size);
    sf::Color fill = {100, 100, 255, 128};
    sf::Color outline = {125, 125, 255, 255};
    rect.setPosition(0, 0);
    rect.setFillColor(fill);
    rect.setOutlineColor(outline);
    return (rect);
}

sf::CircleShape load_gum()
{
    sf::CircleShape circle(5, 30);
    circle.setFillColor(sf::Color::White);
    return (circle);
}

void draw_map(std::vector<std::string> *map)
{
    sf::RectangleShape rect = load_wall();
    sf::CircleShape circle = load_gum();
    mapX = wd->getSize().x / 2 - (((int)(*map)[0].length()) * TILE_WIDTH) / 2;
    mapY = wd->getSize().y / 2 - ((int) map->size()) * TILE_HEIGHT / 2;

    for (int i = 0; i < (int) map->size(); i++)
    {
        for (int j = 0; j < (int) (*map)[i].length(); j++)
        {
            if ((*map)[i][j] == '#' || (*map)[i][j] == '|')
            {
                rect.setPosition(mapX + j * TILE_WIDTH, mapY + i * TILE_HEIGHT);
                wd->draw(rect);
            }
            if ((*map)[i][j] == '.')
            {
                circle.setPosition(mapX + j * TILE_WIDTH + 10, mapY + i * TILE_HEIGHT + 10);
                wd->draw(circle);
            }
            if ((*map)[i][j] == '*')
            {
                circle.setRadius(7);
                circle.setFillColor(sf::Color::Yellow);
                circle.setPosition(mapX + j * TILE_WIDTH + 10, mapY + i * TILE_HEIGHT + 10);
                wd->draw(circle);
                circle.setFillColor(sf::Color::White);
                circle.setRadius(5);
            }
        }
    }
}