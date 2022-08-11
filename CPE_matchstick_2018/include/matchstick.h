/*
** EPITECH PROJECT, 2019
** matchstick.h
** File description:
** header for matchstick project
*/

#ifndef  READ_SIZE
#define  READ_SIZE (100)
#endif

#ifndef MATCHSTICK_H_
#define MATCHSTICK_H_

typedef struct s_map
{
    int lines;
    int max_rmv;
    char **map;
    int finish;
}t_map;

int handle_errors(int ac, char **av);
int my_getnbr(char const *str);
int my_puterror(char const *str);
t_map *create_map(char **av);
void free_values(t_map *map);
char *get_next_line(int fd);
int my_putstr(char const *str);
int my_printf(char const *format, ...);
t_map *catch_player_action(t_map *map);
int chose_turn(t_map *map);
char *use_getline(void);
char *remove_char_from_str(char *str);
int check_if_nb(char *str);
t_map *remove_match_ia(t_map *map);
char get_last_char_str(char *str);

#endif
