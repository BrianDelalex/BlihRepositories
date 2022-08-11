/*
** EPITECH PROJECT, 2019
** draw_menu.cpp
** File description:
** draw menu in sfml mod
*/

#include "my_sfml.hpp"

int menu_key_handler(sf::Event::KeyEvent key, int *gameSelected, int nbGames)
{
    if (key.code == sf::Keyboard::Left)
    {
        if (*gameSelected == 0)
            *gameSelected = nbGames - 1;
        else
            *gameSelected = *gameSelected - 1;
    }
    if (key.code == sf::Keyboard::Right)
    {
        if (*gameSelected == nbGames - 1)
            *gameSelected = 0;
        else
            *gameSelected = *gameSelected + 1;
    }
    if (key.code == sf::Keyboard::Enter)
        return (1);
    return (0);
}

int menu_event_handler(sf::RenderWindow *win, int *gameSelected, int nbGames)
{
    sf::Event event;
    while (win->pollEvent(event))
    {
        if (event.type == sf::Event::KeyPressed)
        {
            return (menu_key_handler(event.key, gameSelected, nbGames));
        }
        if (event.type == sf::Event::Closed)
            win->close();
    }
    return (0);
}

std::string exit_menu(std::string rtn, sf::RenderWindow *win)
{
    win->close();
    
    delete win;
    return (rtn);
}

extern "C" std::string menu_display(std::vector<std::string> gameList)
{
    sf::RenderWindow *win = create_window(1920, 1080, "Menu");
    std::string font_file = PROJECT_DIR;
    font_file.append("/ressources/graphics/sfml/FiraCode-Bold.ttf");
    std::cout << font_file << std::endl;
    sf::Font font;
    if (!font.loadFromFile(font_file))
    {
        std::cout << "ERROR READING FONT: " << font_file << std::endl;
        exit(84);
    }

    std::vector<sf::Text> banners;
    sf::Color c((sf::Uint8)255, (sf::Uint8) 0, 0, (sf::Uint8)255);
    for (int i = 0; i < (int) gameList.size(); i++)
    {
        sf::Text text(std::string(gameList[i]), font, 32);
        text.setFillColor(c);
        text.setCharacterSize((uint) 120);
        text.setPosition(  (((i % 1) + i * 2 + 1 )* ((int) win->getSize().x / (gameList.size() * 2))) - text.getGlobalBounds().width / 2,  win->getSize().y / 2 - text.getGlobalBounds().height / 2);
        banners.push_back(text);
    }
    std::string img_file = PROJECT_DIR;
    sf::Texture img;
    img_file.append("/ressources/graphics/sfml/arrow.png");
    if (!img.loadFromFile(img_file))
    {
        std::cerr << "Error loading arrow: " << img_file << std::endl;
        exit (84);
    }
    img.update(img);
    sf::Vector2f arrowPos = {banners[0].getPosition().x + banners[0].getGlobalBounds().width / 2 - img.getSize().x / 2, banners[0].getPosition().y + banners[0].getGlobalBounds().height + 50};
    sf::Sprite arrow(img);
    arrow.setPosition(arrowPos);
    int gameSelected = 0;
    while (win->isOpen())
    {
        if (menu_event_handler(win, &gameSelected, (int) banners.size()) == 1)
            return (exit_menu(gameList[gameSelected], win));
        arrowPos.x = banners[gameSelected].getPosition().x + banners[gameSelected].getGlobalBounds().width / 2 - img.getSize().x / 2;
        arrow.setPosition(arrowPos);
        win->clear(sf::Color::White);
        for (int i = 0; i < (int) banners.size(); i++)
            win->draw(banners.at(i));
        win->draw(arrow);
        win->display();
    }
    return (exit_menu(std::string("EXIT"), win));
}