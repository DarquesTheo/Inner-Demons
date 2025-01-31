/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** heart_destroy
*/

#include "heart.h"
#include <stdlib.h>

void heart_destroy(heart_t *heart)
{
    for (int i = 0; i < heart->heart_nb; i++) {
        sfSprite_destroy(heart->heart[i]);
    }
    free(heart);
}
