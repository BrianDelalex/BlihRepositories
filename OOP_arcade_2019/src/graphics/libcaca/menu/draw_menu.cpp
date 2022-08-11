/*
** EPITECH PROJECT, 2019
** draw_menu.cpp
** File description:
** draw menu with libcaca
*/

#include "my_libcaca.hpp"


#define BANNERS_PATH "/ressources/graphics/banners/"
#define ARROW_PATH "/ressources/graphics/banners/arrow.txt"


std::tuple<std::string, std::string> create_banner(std::string gameName)
{
    std::string path = PROJECT_DIR;
    path = path + BANNERS_PATH;
    path = path + gameName;
    path = path + ".txt";
    std::cout << path << std::endl;
    std::string str, banner;
    std::ifstream file;
    file.open(path);
    if (!file.is_open())
        return (std::make_tuple(gameName, " ,------.  \n'  .--.  ' \n'--' _|  | \n  .--' __'  \n `---'     \n .---.     \n '---'     \n"));
    while (std::getline(file, str, '\n'))
    {
        if (!str.empty()) {
            str.push_back('E');
            banner.append(str);
        }
    }
    return (std::make_tuple(gameName, banner));

}

std::vector<std::tuple<std::string, std::string>> get_banner(std::vector<std::string> gameList)
{
    std::vector<std::tuple<std::string, std::string>> games;
    for (int i = 0; i < (int) gameList.size(); i++)
    {
        games.push_back(create_banner(gameList.at(i)));
    }
    return (games);
}

void draw_banners(caca_canvas_t *cv, std::vector<std::tuple<std::string, std::string>> banners)
{
    int width = caca_get_canvas_width(cv);
    int heigth = caca_get_canvas_height(cv);
    caca_put_str(cv, width / 4, heigth / 2, std::get<1>(banners[0]).c_str());
    caca_put_str(cv, width * (3 / 4), heigth / 2, std::get<1>(banners[1]).c_str());
}


extern "C" std::string menu_display(std::vector<std::string> gameList)
{
    return (gameList[0]);
    caca_canvas_t *cv;
    caca_display_t *dp = NULL;
    caca_event_t ev;

    while (!dp)
        dp = caca_create_display(NULL);
    cv = caca_get_canvas(dp);
    caca_set_display_title(dp, "Hello!");
    caca_set_color_ansi(cv, CACA_BLACK, CACA_WHITE);
    draw_banners(cv, get_banner(gameList));
    while (1)
    {
        caca_refresh_display(dp);
        caca_get_event(dp, CACA_EVENT_KEY_PRESS, &ev, -1);
    }
    caca_free_display(dp);
    return gameList[0];
}