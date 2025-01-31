/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** rand_int
*/

#include <stdlib.h>

int rand_int(int min, int max)
{
    int r = rand() % (max - min + 1);

    return (r + min);
}
