/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** place_sprite_hitbox
*/

#include "hitbox.h"
#include "utils.h"
#include "vector.h"

void place_sprite_hitbox(hitbox_rect_t *hitbox, sfSprite *sprite)
{
    sfVector2f pos;

    if (hitbox) {
        pos = sfSprite_getPosition(sprite);
        pos = add_vectors(pos, hitbox->offset);
        sfRectangleShape_setPosition(hitbox->rect, pos);
    }
}
