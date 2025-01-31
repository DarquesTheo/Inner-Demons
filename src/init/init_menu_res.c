/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** init_menu_res
*/

#include "res.h"
#include "stdlib.h"

menu_res_t *init_menu_res(void)
{
    menu_res_t *menu = malloc(sizeof(menu_res_t));

    menu->home = sfTexture_createFromFile("res/menu/home.png", NULL);
    menu->died = sfTexture_createFromFile("res/menu/you_died.png", NULL);
    menu->restart = sfTexture_createFromFile("res/menu/restart.png", NULL);
    return menu;
}
