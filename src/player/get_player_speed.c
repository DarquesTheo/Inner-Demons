/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** get_player_speed
*/

#include "game.h"
#include "player.h"

float get_player_speed(game_t *game)
{
    switch (game->player->state) {
        case WALKING:
            return 400;
        case RUNNING:
            return 500;
        case DASHING:
            return 1000;
    }
    return 0;
}
