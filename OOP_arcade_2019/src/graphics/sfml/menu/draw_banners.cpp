/*
** EPITECH PROJECT, 2019
** draw_banners.cpp
** File description:
** draw games banners
*/

#include "my_sfml.hpp"

std::vector<sf::Text *> draw_banners(sf::RenderWindow *wd, const std::vector<std::string> &gameList, sf::Font font)
{
    std::vector<sf::Text *> banners;
    
    sf::Color c((sf::Uint8)255, (sf::Uint8) 0, 0, (sf::Uint8)255);
    
  

    for (int i = 0; i < (int) gameList.size(); i++)
    {
        sf::Text *text = new sf::Text(std::string(gameList[i]), font, 32);
        text->setFillColor(c);
        text->setCharacterSize((uint) 32);
        //text.setString(std::string(gameList.at(i)));
        text->setPosition( 50 * i/*( (i + 1) / gameList.size() ) * wd->getSize().x - text.getGlobalBounds().width / 2*/, 50 * i);// wd->getSize().y / 2);
        banners.push_back(text);
    }
    return (banners);
}