/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** get_ui_mouse_pos
*/

#include "game.h"

sfVector2f get_mouse_ui_pos(game_t *game)
{
    sfVector2f pos = game->info->local_mouse_pos;
    sfVector2u window_size = sfRenderWindow_getSize(game->window);

    pos.x = 100000 + pos.x * 1920 / window_size.x - 960;
    pos.y = 100000 + pos.y * 1080 / window_size.y - 560;
    return pos;
}
