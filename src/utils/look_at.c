/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** look_at
*/

#include "game.h"
#include "const.h"
#include "vector.h"
#include <math.h>

void look_at(sfSprite *sprite, sfVector2f point, float offset)
{
    sfVector2f sprite_pos = sfSprite_getPosition(sprite);
    sfVector2f vec = get_vector_difference(sprite_pos, point);

    sfSprite_setRotation(sprite, atan2(vec.y, vec.x) * 180 / PI + offset);
}
