/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** inventory_insertitem
*/

#include "inventory.h"

void inventory_insertitem(inventory_t *inventory, void *item, sfVector2i pos)
{
    if (pos.x < 0 || pos.x - 1 > inventory->size_x)
        return;
    if (pos.y < 0 || pos.y - 1 > inventory->size_y)
        return;
    (inventory->inv[pos.y][pos.x])->content = item;
    slot_refreshicon(inventory->inv[pos.y][pos.x]);
}

sfBool try_inventory_insertitem(inventory_t *inventory, void *item,
    sfVector2i pos)
{
    if (!slot_isempty(inventory->inv[pos.y][pos.x]))
        return sfFalse;
    inventory_insertitem(inventory, item, pos);
    return sfTrue;
}
