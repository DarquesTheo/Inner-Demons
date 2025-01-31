/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** init_info
*/

#include "game.h"
#include "keybinds.h"
#include "res.h"
#include "stdlib.h"
#include "utils.h"
#include "player.h"
#include "vector.h"

static void init_volume(game_info_t *info)
{
    info->sfx_vol = 100;
    info->music_vol = 100;
}

game_info_t *init_game_info(game_t *game)
{
    game_info_t *info = malloc(sizeof(game_info_t));
    sfVector2u wsize = sfRenderWindow_getSize(game->window);
    sfVector2f wcenter = {wsize.x / 2, wsize.y / 2};

    info->fps = 360;
    info->mouse_pos = wcenter;
    info->last_mouse_pos = wcenter;
    info->last_local_mouse_pos = wcenter;
    info->local_mouse_pos = wcenter;
    info->keybinds = init_keybinds();
    info->inputs = init_inputs();
    info->last_inputs = init_inputs();
    info->mouse = init_mouse_input();
    info->crosshair = init_crosshair(game->res);
    info->debug = sfFalse;
    info->mouse_side = BOTTOM;
    info->in_menu = 0;
    info->current_tileset = game->res->tilesets->floor1;
    init_volume(info);
    return info;
}
