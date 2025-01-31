/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** free_weapon
*/

#include "player.h"
#include <stdlib.h>

void free_weapon(weapon_t *wp)
{
    if (!wp)
        return;
    sfSprite_destroy(wp->sprite);
    sfClock_destroy(wp->clock);
    free(wp->name);
    free(wp);
}
