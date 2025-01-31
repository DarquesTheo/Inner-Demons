/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** init_crosshair
*/

#include "res.h"

sfSprite *init_crosshair(res_t *res)
{
    sfSprite *crosshair = sfSprite_create();

    sfSprite_setTexture(crosshair, res->crosshair1, 0);
    sfSprite_setScale(crosshair, (sfVector2f){5, 5});
    sfSprite_setOrigin(crosshair, (sfVector2f){4.5, 4.5});
    return crosshair;
}
