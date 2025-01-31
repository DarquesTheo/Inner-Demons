/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** vector_print
*/

#include "game.h"
#include <stdio.h>

void print_vectorf(sfVector2f vec)
{
    printf("(%.2f, %.2f)\n", vec.x, vec.y);
}

void print_vectori(sfVector2i vec)
{
    printf("(%d, %d)\n", vec.x, vec.y);
}
