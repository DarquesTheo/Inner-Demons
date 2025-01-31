/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** free_map
*/

#include "map.h"
#include "enemies.h"
#include "objects.h"
#include "anim.h"
#include <stdlib.h>

void free_current_map(game_t *game)
{
    room_t *room = game->map;

    if (room == NULL)
        return;
    if (room->collisions != NULL)
        free(room->collisions);
    if (room->int_layer1 != NULL)
        free(room->int_layer1);
    if (room->int_layer2 != NULL)
        free(room->int_layer2);
    if (room->layer1 != NULL)
        sfVertexArray_destroy(room->layer1);
    if (room->layer2 != NULL)
        sfVertexArray_destroy(room->layer2);
    free_all_mobs(game);
    if (room->objects != NULL)
        free_objects(room->objects);
    if (game->anims != NULL)
        free_anim_list(&(game->anims));
    free(room);
}
