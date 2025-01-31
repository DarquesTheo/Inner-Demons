/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** inventory_additem
*/

#include "inventory.h"

static int try_additem_row(inventory_t *inventory, int i)
{
    for (int j = 0; inventory->inv[i][j] != NULL; j++) {
        if (slot_isempty(inventory->inv[i][j]))
            return j;
    }
    return - 1;
}

sfBool inventory_additem(inventory_t *inventory, void *item)
{
    int j = - 1;
    int i = 0;

    if (item == NULL)
        return 0;
    for (; inventory->inv[i] != NULL; i++) {
        j = try_additem_row(inventory, i);
        if (j >= 0)
            break;
    }
    if (j < 0)
        return 0;
    inventory_insertitem(inventory, item, (sfVector2i){j, i});
    inventory_applyiconslot(inventory, (sfVector2i){j, i});
    return 1;
}
