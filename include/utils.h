/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** utils
*/

#ifndef UTILS_H_
    #define UTILS_H_
    #include "game.h"

sfIntRect init_intrect(int width, int height);
sfVector2f get_mouse_pos(sfRenderWindow *window);
int get_point_pos_in_rectangle(sfVector2f p, sfVector2f rect_size);
int get_point_side_in_rectangle(sfVector2f p, sfVector2f rect_size);
void look_at(sfSprite *sprite, sfVector2f point, float offset);
char *my_atoi(int value);

//mouse position
sfVector2f get_mouse_ui_pos(game_t *game);

//create vector
sfVector2f v2f(float x, float y);
sfVector2i v2i(int x, int y);

//tilemap
sfVector2i get_pos_tile(room_t *room, sfVector2f pos);
void print_int_map(int *map, sfVector2i size);
sfVector2f *get_rectangle_points(int nb_by_edge, sfRectangleShape *rect);

//RANDOM GENERATION
float rand_float(float min, float max);
int rand_int(int min, int max);

//string
void rm_char_from_str(char *str, char c);

#endif /* !UTILS_H_ */
