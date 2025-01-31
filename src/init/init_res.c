/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-baptiste.camerlynck
** File description:
** init_res
*/

#include "res.h"
#include "map.h"
#include <stdlib.h>

res_t *init_res(void)
{
    res_t *res = malloc(sizeof(res_t));

    res->crosshair1 =
    sfTexture_createFromFile("res/crosshairs/crosshairv1.png", NULL);
    res->player_res = init_player_res();
    res->weapons = init_weapons_res();
    res->tilesets = init_tilesets();
    res->obj_res = init_obj_res();
    res->projectile_mob = init_projectile_mob_struct();
    res->sbuf_list = NULL;
    res->tex_list = NULL;
    res->pool_floor1 = list_dir_files("res/map/floor1/lua");
    res->pool_floor2 = list_dir_files("res/map/floor2/lua");
    res->pool_floor3 = list_dir_files("res/map/floor3/lua");
    res->inv = init_inv_res();
    res->menu = init_menu_res();
    res->artefact = init_res_artefact();
    res->fonts = init_fonts();
    return res;
}
