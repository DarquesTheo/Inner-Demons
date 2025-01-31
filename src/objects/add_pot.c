/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** pot
*/

#include "objects.h"
#include "vector.h"
#include "utils.h"
#include "hitbox.h"
#include <stdlib.h>

void add_pot(pot_t **pots, sfVector2f pos, sfTexture *tex)
{
    pot_t *pot = malloc(sizeof(pot_t));

    pot->sprite = sfSprite_create();
    pos.y -= 16 * 5;
    sfSprite_setPosition(pot->sprite, v2f(pos.x, pos.y));
    sfSprite_setTexture(pot->sprite, tex, 0);
    pot->rect = init_intrect(16, 16);
    sfSprite_setTextureRect(pot->sprite, pot->rect);
    sfSprite_setScale(pot->sprite, v2f(5, 5));
    pot->hitbox = create_rect_hitbox(v2f(80, 80), v2f(40, 40));
    place_sprite_hitbox(pot->hitbox, pot->sprite);
    pot->state = POT_INTACT;
    pot->prev = NULL;
    pot->next = *pots;
    if (*pots != NULL)
        (*pots)->prev = pot;
    *pots = pot;
}
