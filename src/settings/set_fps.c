/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-baptiste.camerlynck
** File description:
** fps_change
*/

#include "game.h"

void set_fps(game_t *game, int fps)
{
    sfRenderWindow_setFramerateLimit(game->window, fps);
    game->fps = fps;
}
