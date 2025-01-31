/*
** EPITECH PROJECT, 2024
** get_nbr_enemies.c
** File description:
** get nemies nbr
*/

#include "game.h"
#include "enemies.h"
#include "map.h"

int get_nbr_enemies(game_t *game)
{
    int i = 0;

    for (mob_t *node = game->map->mobs; node != NULL; node = node->next) {
        if (node->type < 6)
            i++;
    }
    return i;
}
