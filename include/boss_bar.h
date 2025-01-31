/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** boss_bar
*/

#ifndef BOSS_BAR_H_
    #define BOSS_BAR_H_
    #include "game.h"
    #define MAX_HP_X 956

typedef struct ui_hp_boss_s {
    sfSprite *sprite;
    sfRectangleShape *rect;
    sfText *name;
} ui_hp_boss_t;

void draw_boss_bar(game_t *game);
ui_hp_boss_t *init_ui_boss_bar(res_t *res);

#endif
