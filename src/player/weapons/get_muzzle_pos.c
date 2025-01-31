/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** get_muzzle_pos
*/

#include "game.h"
#include "vector.h"

sfVector2f get_muzzle_pos(sfSprite* sprite, sfVector2f muzzlepos)
{
    sfVector2f scale = sfSprite_getScale(sprite);
    sfVector2f origin = sfSprite_getOrigin(sprite);

    muzzlepos.x *= scale.x;
    muzzlepos.y *= scale.y;
    muzzlepos.x -= origin.x * scale.x;
    muzzlepos.y -= origin.y * scale.y;
    return muzzlepos;
}
