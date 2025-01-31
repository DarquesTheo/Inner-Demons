/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** inventory_applyiconslot
*/

#include "inventory.h"

void inventory_applyiconslot(inventory_t *inv, sfVector2i pos)
{
    slot_refreshicon(inv->inv[pos.y][pos.x]);
}
