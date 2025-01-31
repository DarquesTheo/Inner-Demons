/*
** EPITECH PROJECT, 2024
** game_menu.
** File description:
** game_menu
*/

#ifndef GAME_MENU_H_
    #define GAME_MENU_H_
    #include <SFML/Graphics.h>
    #include "slider.h"

typedef struct game_menu_s {
    sfRectangleShape *shade;
    sfSprite *res1_button;
    sfSprite *res2_button;
    sfSprite *res3_button;
    sfSprite *bg;
    sfSprite *home_button;
    sfSprite *resume_button;
    sfText *sfx_text;
    sfText *music_text;
    sfText *sfx_percent;
    sfText *music_percent;
    slider_t *sfx_slider;
    slider_t *music_slider;
} game_menu_t;

game_menu_t *init_game_menu(void);
void handle_game_menu(game_t *game);
void button_pressed_game_menu(game_t *game, sfEvent event);
void check_volume_slider(game_t *game);

#endif
