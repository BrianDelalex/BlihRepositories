/*
** EPITECH PROJECT, 2019
** parsing.c
** File description:
** parse the input
*/

#include "my.h"

t_control *parsing(char *cmd)
{
    int len = ;
    t_control *ctrl = malloc(sizeof(t_control));
    cmd = cut_repetitive_char(cmd, 32);

    if (cmd[0] == 's' && cmd[1] == 'h' && cmd[2] == 'o' && cmd[3] == 'w') {
        ctrl->show = 1;
        ctrl->sort = 0;
	ctrl->show_nb[0] = cmd[5] + 48;
	ctrl->show_nb[1] = cmd[7] + 48;
    } else if (cmd[0] == 's' && cmd[1] == 'o') {
        ctrl->sort = 1;
        ctrl->show = 0;
	for (; cmd[5 + len] && cmd[5 + len] != 'W'; len++);
        ctrl->sort_by = malloc(sizeof(char) * len);
        for (int i = 0; cmd[5 + i] && cmd[5 + i] != 'W'; i++)
            ctrl->sort_by[i] = cmd[5 + i];
    }
}
