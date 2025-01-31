/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** vector
*/

#include "game.h"
#include "mylib.h"

//pos2 - pos1
sfVector2f get_vector_difference(sfVector2f pos1, sfVector2f pos2)
{
    return (sfVector2f){pos2.x - pos1.x, pos2.y - pos1.y};
}

sfVector2f mult_vector(sfVector2f vec, float fac)
{
    return (sfVector2f){vec.x * fac, vec.y * fac};
}

sfVector2f mult_vectors(sfVector2f vec1, sfVector2f vec2)
{
    return (sfVector2f){vec1.x * vec2.x, vec1.y * vec2.y};
}

sfVector2f normalize_vector(sfVector2f vec)
{
    float norm = vec.x * vec.x + vec.y * vec.y;

    if (norm == 0)
        return vec;
    norm = sqrt(norm);
    return (sfVector2f){vec.x / norm, vec.y / norm};
}

sfVector2f add_vectors(sfVector2f vec1, sfVector2f vec2)
{
    return (sfVector2f){vec1.x + vec2.x, vec1.y + vec2.y};
}
