/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** on_each_fps_cursor
*/

#include "game.h"
#include "utils.h"
#include "vector.h"
#include "player.h"

void on_each_fps_cursor(game_t *game)
{
    sfVector2i wmouse_pos = sfMouse_getPositionRenderWindow(game->window);
    sfVector2f mouse_pos = v2f(wmouse_pos.x, wmouse_pos.y);

    game->info->last_local_mouse_pos = game->info->local_mouse_pos;
    game->info->local_mouse_pos = mouse_pos;
    game->info->last_mouse_pos = game->info->mouse_pos;
    game->info->mouse_pos = sfRenderWindow_mapPixelToCoords(game->window,
    wmouse_pos, game->player->cam);
    sfSprite_setPosition(game->info->crosshair, game->info->mouse_pos);
    sfRenderWindow_drawSprite(game->window, game->info->crosshair, NULL);
}
