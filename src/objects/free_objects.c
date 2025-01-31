/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** free_objects
*/

#include "objects.h"
#include <stdlib.h>

void free_objects(objects_t *obj)
{
    void *next = NULL;

    for (pot_t *tmp = obj->pots; tmp; tmp = next) {
        next = tmp->next;
        free_hitbox(tmp->hitbox);
        sfSprite_destroy(tmp->sprite);
        free(tmp);
    }
    for (spike_t *tmp = obj->spikes; tmp; tmp = next) {
        next = tmp->next;
        free_hitbox(tmp->hitbox);
        sfClock_destroy(tmp->clock);
        sfSprite_destroy(tmp->sprite);
        free(tmp);
    }
    free(obj);
}
