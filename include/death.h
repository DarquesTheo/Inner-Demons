/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** death
*/

#ifndef DEATH_H_
    #define DEATH_H_
    #include "SFML/Graphics.h"
    #include "button.h"
    #include "game.h"

    #define D_TEXT_SIZE 600, 180
    #define D_TEXT_POS 100000 - 300, 100000 - 450

typedef struct death_menu_s {
    sfRectangleShape *bg;
    sfRectangleShape *text;
    button_t *quit;
    button_t *restart;
    sfBool active;
} death_menu_t;

void draw_death_menu(sfRenderWindow *window, death_menu_t *menu);
void check_death_btn_state(game_t *game);
void death_menu_check_click(game_t *game);

#endif /* !DEATH_H_ */
