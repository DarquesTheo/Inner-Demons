/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** get_random_map
*/

#include "game.h"
#include "map.h"
#include "res.h"
#include <stdlib.h>
#include <stdio.h>
#include "system.h"

static char *get_map_at_hint(linked_list_t *list, int hint)
{
    int count = 0;

    for (linked_list_t *tmp = list; tmp; tmp = tmp->next) {
        if (hint == count)
            return (char *)tmp->data;
        count++;
    }
    return NULL;
}

char *get_random_map_file(game_t *game)
{
    linked_list_t *pool = NULL;
    int map_pool_size;
    int hint;
    char *map_file;

    if (game->system->biome == BIOME1)
        pool = game->res->pool_floor1;
    if (game->system->biome == BIOME2)
        pool = game->res->pool_floor2;
    if (game->system->biome == BIOME3)
        pool = game->res->pool_floor3;
    map_pool_size = get_list_size(pool);
    hint = rand() % map_pool_size;
    map_file = get_map_at_hint(pool, hint);
    while (!map_file) {
        printf("Wront hint in pool size\n");
        hint = rand() % map_pool_size;
        get_map_at_hint(pool, hint);
    }
    return map_file;
}
