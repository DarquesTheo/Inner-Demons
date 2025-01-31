/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** get_shoot_distance
*/

#include "game.h"
#include "const.h"
#include "vector.h"
#include <math.h>

sfVector2f get_bullet_spawn(sfSprite *weapon, sfVector2f offset)
{
    float angle = sfSprite_getRotation(weapon) * PI / 180;
    sfVector2f pos = sfSprite_getPosition(weapon);
    float spawnx = pos.x + offset.x * cos(angle) - offset.y * sin(angle);
    float spawny = pos.y + offset.x * sin(angle) + offset.y * cos(angle);

    return (sfVector2f){spawnx, spawny};
}

//enter the distance from the sprite origin
sfVector2f get_bullet_start(sfSprite *sprite, float distance, float offset)
{
    float angle = (sfSprite_getRotation(sprite) + offset) * PI / 180;
    sfVector2f pointing_vector = {cos(angle), sin(angle)};

    return mult_vector(pointing_vector, distance);
}
