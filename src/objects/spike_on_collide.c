/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** spike_on_collide
*/

#include "game.h"
#include "objects.h"
#include "player.h"

void spike_on_collide(game_t *game, spike_t *spike)
{
    if (spike->rect.left == 2 * spike->rect.width
    && game->player->state != DASHING) {
        player_take_dmg(game, 1);
    }
}
