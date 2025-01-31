/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** init_death_menu
*/

#include "death.h"
#include "res.h"
#include "game.h"
#include "ui.h"

static void init_btn(death_menu_t *menu, res_t *res)
{
    menu->quit = button_create_default();
    button_seticon(menu->quit, res->menu->home);
    button_seticoncolor(menu->quit, sfWhite);
    button_setsize(menu->quit, (sfVector2f){400, 150});
    button_setposition(menu->quit, (sfVector2f){100000 - 200, 100000 - 100});
    menu->quit->color->c_default = sfTransparent;
    menu->quit->color->c_hover = sfTransparent;
    menu->quit->color->c_pressed = sfTransparent;
    menu->restart = button_create_default();
    button_seticon(menu->restart, res->menu->restart);
    button_seticoncolor(menu->restart, sfWhite);
    button_setsize(menu->restart, (sfVector2f){400, 150});
    button_setposition(menu->restart, (sfVector2f){100000 - 200, 100000 +
        100});
    menu->restart->color->c_default = sfTransparent;
    menu->restart->color->c_hover = sfTransparent;
    menu->restart->color->c_pressed = sfTransparent;
    button_setcallback(menu->restart, (void *)(void *)&restart_game);
    button_setcallback(menu->quit, (void *)(void *)&go_home);
}

death_menu_t *init_death_menu(res_t *res)
{
    death_menu_t *menu = malloc(sizeof(death_menu_t));

    menu->bg = sfRectangleShape_create();
    sfRectangleShape_setSize(menu->bg, (sfVector2f){2000, 2000});
    sfRectangleShape_setPosition(menu->bg, (sfVector2f){100000 - 1920 / 2,
        100000 - 1080 / 2});
    sfRectangleShape_setFillColor(menu->bg, (sfColor){0, 0, 0, 120});
    menu->text = sfRectangleShape_create();
    sfRectangleShape_setSize(menu->text, (sfVector2f){D_TEXT_SIZE});
    sfRectangleShape_setPosition(menu->text, (sfVector2f){D_TEXT_POS});
    sfRectangleShape_setTexture(menu->text, res->menu->died, 0);
    init_btn(menu, res);
    menu->active = sfFalse;
    return menu;
}
