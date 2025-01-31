/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** inventory_getslotcontent
*/

#include "inventory.h"

void *inventory_getslotcontent(inventory_t *inventory, sfVector2i pos)
{
    if (pos.x < 0 || pos.x - 1 > inventory->size_x)
        return NULL;
    if (pos.y < 0 || pos.y - 1 > inventory->size_y)
        return NULL;
    return (inventory->inv[pos.y][pos.x])->content;
}
