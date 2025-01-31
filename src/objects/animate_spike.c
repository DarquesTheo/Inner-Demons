/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** animate_spike
*/

#include "game.h"
#include "system.h"
#include "objects.h"
#include "vector.h"
#include "utils.h"

static void change_spike_frame(spike_t *spike)
{
    spike->rect.left += spike->rect.width;
    if (spike->rect.left >= 3 * spike->rect.width) {
        spike->rect.left = 0;
    }
    sfSprite_setTextureRect(spike->sprite, spike->rect);
}

void animate_spike(game_t *game, spike_t *spike)
{
    sfTime time;
    float delta;

    if (game->system->statut == ENDING) {
        if (spike->rect.left != 0) {
            spike->rect.left = 0;
            sfSprite_setTextureRect(spike->sprite, spike->rect);
        }
        return;
    }
    time = sfClock_getElapsedTime(spike->clock);
    delta = time.microseconds / 1000000.0;
    if (delta * 1 > 1) {
        change_spike_frame(spike);
        sfClock_restart(spike->clock);
    }
}
