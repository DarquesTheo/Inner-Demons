/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** free_prog
*/

#include "game.h"
#include "res.h"
#include <stdlib.h>

static void free_game_info(game_info_t *info)
{
    if (info == NULL)
        return;
    sfSprite_destroy(info->crosshair);
    free(info->inputs);
    free(info->last_inputs);
    free(info->keybinds);
    free(info->mouse);
    free(info);
}

void free_prog(game_t *game)
{
    free_game_info(game->info);
    free_game_not_res_or_window(game);
    sfRenderWindow_destroy(game->window);
    free_res(game->res);
    free(game);
}
