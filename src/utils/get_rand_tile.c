/*
** EPITECH PROJECT, 2024
** get_rand_tile.c
** File description:
** get a random tile
*/

#include "game.h"
#include <math.h>
#include "map.h"
#include <stdlib.h>

sfVector2f get_rand_tile(game_t *game)
{
    sfVector2f vector;
    int size;
    int random;

    for (size = 0; size < game->map->size.x * game->map->size.y; size++);
    random = rand() % size;
    while (game->map->collisions[random] != 0)
        random = rand() % size;
    vector.y = random / game->map->size.x;
    vector.x = random % game->map->size.x;
    vector.x *= game->map->tilesize.x * game->map->scale.x;
    vector.y *= game->map->tilesize.y * game->map->scale.y;
    vector.x += 8;
    vector.y += 8;
    return vector;
}
