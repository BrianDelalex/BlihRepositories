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
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>



/* STRUCT */

typedef struct framebuffer_s
{
    unsigned char *pixel;
    unsigned int height;
    unsigned int width;
}framebuffer_t;

typedef struct s_maps
{
    int **map3d;
    sfVector2f **map2d;
    sfVector2f size;
    sfVector2f scale;
    int x_select;
    int y_select;
}t_maps;

typedef struct s_render_image
{
    sfTexture *texture;
    sfSprite *sprite;
}render_image_t;

typedef struct s_render
{
    sfRenderWindow *wdw;
    framebuffer_t *fb;
    sfClock *clock;
    sfSprite *sp_fb;
    sfTexture *tx_fb;
    t_maps *maps;
    int tool;
    long money;
    render_image_t *field_tool;
    int nb_of_field;
    sfSprite **fields;
}t_render;

typedef struct list_a
{
    struct list_a   *prev;
    int             data;
    struct list_a   *next;
} list;

typedef struct info_t
{
    int iter;
    int size;
    int bol;
    int nbr_null;
} info_t;

/* PROTO */

t_render *create_render(int width, int height, int nb_bit_pixel);
void render_window(t_render *render);
void analyse_events_choice(t_render *render, sfEvent evt);
framebuffer_t *create_framebuffer(unsigned int width, unsigned int height);
void put_pixel(framebuffer_t *fb, unsigned int x, unsigned int y, sfColor c);
sfVector2f project_iso_point(int x, int y, int z);
void draw_2d_map(t_render *rd);
sfVector2f **create_2d_map(int **map3D, int x, int y);
sfVertexArray *create_line(sfVector2f point1 , sfVector2f point2);
void fill_tiles(t_render *render, sfVector2f **map2d, int i, int j);
void chose_map_size(t_render *rd);
void draw_rectangle(framebuffer_t *fb, sfVector2f p1, sfVector2f s, sfColor c);
void draw_text(t_render *rd, char *str, sfVector2f pos, int size);
void initiate_game(t_render *rd);
void analyse_events(t_render *rd, sfEvent evt);
void slide_map(t_render *rd, int x, int y);
void use_tools(t_render *rd, sfMouseButtonEvent evt);
render_image_t *create_render_image(char const *filepath, float x, float y);
sfSprite **add_sprite_to_spritetab(sfSprite **tab, sfSprite *vec);
void manage_game_click(t_render *rd, sfMouseButtonEvent evt);
void manage_time(t_render *rd, sfClock *cl);
sfSprite **remove_sprite_from_spritetab(sfSprite **tab, int index);
void check_altitude(t_render *rd);

/* BUILT IN */
void error_management(int, char **);
void help_function(void);

/* LIB */
char *return_get_line(char *, char *);
char *get_next_line(int);
char *int_to_char(int);
char *long_to_char(long);
char *strconcat(char *, char *);
int len_tab(char **);
list *my_params_to_list(char **argv, int argc);
char **str_to_tab(char *, char);
int nbr_char_str(char *, char);
list *circle_double_list(char **, int);
char **pars_file(char **);
int my_printf(char const *, ...);
char **fill_in_pars(char const *, char **);
void switch_type_1(char **, int, va_list);
void function_flags(char **, int);
void oct_convert(int);
char *helping_flag(char **, int, int, char *);
void hexa_convert(long);
char *call_hex_convert(int, char *, int);
void case_c(va_list);
void case_x(va_list);
void case_o(va_list);
void case_s(va_list);
void case_ss(va_list, int);
void case_b(va_list);
void case_p(va_list);
void case_u(va_list);
void case_d(va_list);
void case_pourcent();
void puterror(char *);
int my_getnbr(char const *);
int my_put_nbr(int);
void my_put_tab(char **);
char *my_revstr(char *);
int my_strlen(char const *);
int len(char *);
char *my_strcpy(char *, char *);
char *my_strcopy(char *, char *);
char *my_strstr(char  *, char *);
void my_putstr(char *);
void my_putchar(char);

#endif
