/*
** EPITECH PROJECT, 2018
** create_linked_list.c
** File description:
** creates list
*/

#include "struct.h"
#include <stdlib.h>

t_vector *create_vector_list2(int i, int j, t_map map, t_vector *list)
{
    t_vector *tmp;

    if (map.map[i][j] == 'O') {
        tmp = malloc(sizeof(t_vector));
        tmp->x = j;
        tmp->y = i;
        if (list != NULL) {
            tmp->next = malloc(sizeof(t_vector));
            tmp->next = list;
        } else
            tmp->next = NULL;
        list = tmp;
    }
    return (list);
}

t_vector *create_vector_list(t_map map)
{
    t_vector *list = NULL;

    for (int i = 0; i <= map.lines; i++) {
        for (int j = 0;j < map.cols; j++) {
            list = create_vector_list2(i, j, map, list);
        }
    }
    return(list);
}
