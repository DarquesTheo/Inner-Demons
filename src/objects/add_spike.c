/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** spike
*/

#include "objects.h"
#include "vector.h"
#include "utils.h"
#include <stdlib.h>

void add_spike(spike_t **spikes, sfVector2f pos, sfTexture *tex)
{
    spike_t *spike = malloc(sizeof(spike_t));

    spike->sprite = sfSprite_create();
    pos.y -= 16 * 10;
    sfSprite_setPosition(spike->sprite, v2f(pos.x, pos.y));
    sfSprite_setTexture(spike->sprite, tex, 0);
    spike->clock = sfClock_create();
    spike->time_buf = 0.0f;
    spike->rect = init_intrect(16, 32);
    sfSprite_setTextureRect(spike->sprite, spike->rect);
    sfSprite_setScale(spike->sprite, v2f(5, 5));
    spike->hitbox = create_rect_hitbox(v2f(80, 80), v2f(40, 40 + 80));
    place_sprite_hitbox(spike->hitbox, spike->sprite);
    spike->prev = NULL;
    spike->next = *spikes;
    if (*spikes != NULL)
        (*spikes)->prev = spike;
    *spikes = spike;
}
