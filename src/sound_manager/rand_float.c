/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** rand_float
*/

#include <stdlib.h>

float rand_float(float min, float max)
{
    float scale = rand() / (float)RAND_MAX;

    return min + scale * (max - min);
}
