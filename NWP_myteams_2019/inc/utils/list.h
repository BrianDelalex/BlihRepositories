/*
** EPITECH PROJECT, 2019
** list.h
** File description:
** list header
*/

#ifndef LIST_H
#define LIST_H

# include <stdlib.h>

# define DEFAULT_NAME_LENGTH 32

typedef struct list_s
{
    void *item;
    struct list_s *next;
}list_t;

list_t *list_add_node(list_t *list, void *item);
list_t *list_find_node(list_t *list, void *item);
int list_get_lenght(list_t *list);
list_t *list_remove_node(list_t *list, list_t *rm);
list_t *list_init(void);
void list_free(list_t *list);



#endif