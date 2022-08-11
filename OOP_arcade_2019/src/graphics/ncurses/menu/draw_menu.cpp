/*
** EPITECH PROJECT, 2019
** draw_menu.cpp
** File description:
** draw menu in NCURSES
*/

#include "my_ncurses.hpp"
#include "tuple"
#include "fstream"

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

std::string read_arrow()
{
    std::string path = PROJECT_DIR;
    path = path + ARROW_PATH;
    std::ifstream file;
    std::string str;
    std::string arrow;
    file.open(path);
    if (!file.is_open())
        return ("   /\\   ");
    while (std::getline(file, str, '\n'))
    {
        if (!str.empty()) {
            str.push_back('E');
            arrow.append(str);
        }
    }
    return (arrow);
}

extern "C" std::string menu_display(std::vector<std::string> gameList)
{
    std::vector<std::tuple<std::string, std::string>> banners = get_banner(gameList);
    WINDOW *win;
    std::string arrow = read_arrow();
    initscr();
    cbreak();
    noecho();
    refresh();
    start_color();
    init_pair(1, COLOR_YELLOW, COLOR_RED);
    init_pair(2, COLOR_BLUE, COLOR_BLACK);
    win = create_window(LINES, COLS, 0, 0);
    nodelay(win, true);
    mvwprintw(win, 0, 10, "Menu");

    std::vector<arcd::Vec2d> pos = create_menu(win, &banners);
    int curPos = 0;
    int key;
    draw_arrow(win, pos.at(0).x, pos.at(0).y, arrow);
    keypad(stdscr, TRUE);
    while ((key = getch()) != 27)
    {
        if (key == KEY_LEFT) 
        {
            if (curPos < ((int) pos.size()) - 1) {
                curPos++;
            } else
                curPos = 0;
        }
        if (key == KEY_RIGHT) 
        {
            if (curPos == 0) {
                curPos = ((int) pos.size()) - 1;
            } else
                curPos--;
        }
        if (key == '\n') {
            break;
        }
        wclear(win);
        box(win, 0, 0);
        mvwprintw(win, 0, COLS / 2, "Menu");
        create_menu(win, &banners);
        wrefresh(win);
        draw_arrow(win, pos.at(curPos).x, pos.at(curPos).y, arrow);
    }
    box(win, ' ', ' '),
    wborder(win, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
    wrefresh(win);
    delwin(win);
    endwin();
    return (std::get<0>(banners.at(curPos)));
}