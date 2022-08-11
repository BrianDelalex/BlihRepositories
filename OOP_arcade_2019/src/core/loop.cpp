/*
** EPITECH PROJECT, 2019
** loop.cpp
** File description:
** core loop
*/

#include "core.hpp"
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

void loop(arcd::render *rd, GraphicsManager *graphM, GameManager *gameM)
{
    int key;
   
    while (1)
    {
        key = graphM->display(rd);
        // if (key == -1)
        //     exit(0);
        rd = gameM->update((uint) key);
        if (key == 103)
            graphM->previous(rd);
        if (key == 104)
            graphM->next(rd);
        if (key == 98) {
            rd = gameM->previous();
        }
        if (key == 110) {
            rd = gameM->next();
        }
    }
}