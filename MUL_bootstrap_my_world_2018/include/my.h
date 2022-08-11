/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** header
*/

#ifndef MY_H_
#define MY_H_


/* INCLUDE */

#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include <SFML/System/Export.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Graphics/Rect.h>
#include <SFML/Graphics/Types.h>
#include <SFML/Graphics/PrimitiveType.h>
#include <SFML/Graphics/RenderStates.h>
#include <SFML/Graphics/Vertex.h>
#include <SFML/Window/Event.h>
#include <SFML/Window/VideoMode.h>
#include <SFML/Window/WindowHandle.h>
#include <SFML/Window/Window.h>
#include <SFML/System/Vector2.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdlib.h>
#include <math.h>

/* STRUCT */

typedef struct framebuffer_s
{
    unsigned char *pixel;
    unsigned int height;
    unsigned int width;
}framebuffer_t;


typedef struct s_render
{
    sfRenderWindow *wdw;
    framebuffer_t *fb;
    sfClock *clock;
    sfSprite *sp_fb;
    sfTexture *tx_fb;
}t_render;

/* PROTO */

t_render *create_render(int width, int height, int nb_bit_pixel);
void render_window(t_render *render, sfVector2f **map2d);
void analyse_events(t_render *render, sfEvent evt);
framebuffer_t *create_framebuffer(unsigned int width, unsigned int height);
void put_pixel(framebuffer_t *fb, unsigned int x, unsigned int y, int value);
sfVector2f project_iso_point(int x, int y, int z);
int draw_2d_map(sfRenderWindow *window, sfVector2f **map2d);
sfVector2f **create_2d_map(int **map3D);
sfVertexArray *create_line(sfVector2f point1 , sfVector2f point2);

/* LIB */

char **add_char_to_tab(char *str, char **str_tab);
char *convert_to_binarie(int nb);
char *convert_to_hexa(int nb, int min);
char *convert_to_octal(int nb);
char *cut_repetitiv_char(char *str, char c);
int my_power(int nb, int p);
int my_printf(char const *format, ...);
void my_putchar(char c);
void my_putnbr(int i);
int my_putstr(char const *str);
void my_puttab(char **tab);
char **my_str_to_tab(char *str, char c);
int my_strcmp(char *str1, char *str2);
char *my_strconcat(char *str1, char *str2);
char *my_strcpy(char *dest, char *src);
int my_strlen(char *str);
int my_strstr(char *str1, char *str2);
char *my_tab_to_str(char **tab, char c);
char *remove_char_from_str(char *str);
char **remove_str_to_tab(char **tab, int index);
void check_and_print(va_list *list, char const *form, int *i, int *ct);
int my_non_printable(char *str);
int count_nbr_digit(int nb);
int tab_length(char **tab);
int my_puterror(char const *str);

#endif
