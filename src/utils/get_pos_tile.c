/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** get_pos_tile
*/

#include "game.h"
#include <math.h>
#include "map.h"

//return the number of the tile where the pos is
sfVector2i get_pos_tile(room_t *room, sfVector2f pos)
{
    sfVector2f scale = room->scale;
    sfVector2f transform = room->transform;
    sfVector2i tilesize = room->tilesize;
    sfVector2i tile = {floor((pos.x + transform.x) / tilesize.x / scale.x),
    floor((pos.y + transform.y) / tilesize.y / scale.y)};

    return tile;
}
