/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** menu
*/

#ifndef MENU_H_
    #define MENU_H_
    #include <SFML/Graphics.h>
    #include "SFML/Audio.h"

typedef enum {
    MENU,
    OPTION,
    INFO
} menu_statut_t;

typedef struct menu_s {
    int f_flag;
    sfVector2f window_size;
    menu_statut_t statut;
    int in_animation;
    sfClock *clock;
    sfSprite *quit_button;
    sfSprite *res1_button;
    sfSprite *res2_button;
    sfSprite *res3_button;
    sfSprite *home_button;
    sfSprite *htp;
    sfSprite *bg;
    sfSprite *play_button;
    sfSprite *option_button;
    sfSprite *exit_button;
    sfMusic *music;
    sfText *in_game_time;
} menu_t;

menu_t *init_menu(game_t *game);
void change_resolution(game_t *game, int x, int y);

#endif /* !MENU_H_ */
