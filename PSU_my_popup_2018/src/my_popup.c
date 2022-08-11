/*
** EPITECH PROJECT, 2018
** my_popup.c
** File description:
** write the given str in the very middle of the terminal
*/

#include <ncurses.h>

int my_strlen(char *str);

int main(int ac, char **av)
{
    initscr();

    for (int i = 0; i < LINES; i ++) {
        for (int j = 0; j < COLS; j++) {
            if (i == LINES / 2 && j == (COLS / 2 - my_strlen(av[1]) / 2))
                printw(av[1]);
            else
                printw(" ");
        }
    }
    refresh();
    while (getch() != 32);
    refresh();
    endwin();
    return (0);
}