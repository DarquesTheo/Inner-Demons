/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** player_w_spike_col
*/

#include "player.h"
#include "vector.h"
#include "objects.h"
#include "map.h"
#include "anim.h"

void player_w_spike_col(game_t *game)
{
    for (spike_t *tmp = game->map->objects->spikes; tmp; tmp = tmp->next) {
        if (are_rect_colliding(game->player->dep_hitbox->rect,
        tmp->hitbox->rect)) {
            spike_on_collide(game, tmp);
        }
    }
}
