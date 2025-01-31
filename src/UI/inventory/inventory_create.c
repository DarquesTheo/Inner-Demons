/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** inventory_create
*/

#include "inventory.h"

/* Malloc inv every cell is NULL by default */
static slot_t ***malloc_inv(inventory_t *inventory, sfVector2f pos,
    res_t *res)
{
    slot_t ***inv = malloc(sizeof(slot_t **) * (inventory->size_y + 1));
    sfVector2f cur_pos = pos;

    inv[inventory->size_y] = NULL;
    for (int i = 0; i < inventory->size_y; i++) {
        inv[i] = malloc(sizeof(slot_t *) * (inventory->size_x + 1));
        inv[i][inventory->size_x] = NULL;
        for (int j = 0; j < inventory->size_x; j++) {
            inv[i][j] = slot_create_default(res);
            cur_pos = (sfVector2f) {pos.x + (j * SLOT_SIZE_X), pos.y + (i *
                SLOT_SIZE_Y)};
            slot_setposition(inv[i][j], cur_pos);
        }
    }
    return inv;
}

/* size is the x and y size of the inventory grid (number of cell )*/
inventory_t *inventory_create(sfVector2i size, sfVector2f pos, res_t *res)
{
    inventory_t *inv = malloc(sizeof(inventory_t));

    inv->size_x = size.x;
    inv->size_y = size.y;
    inv->inv = malloc_inv(inv, pos, res);
    inv->active = sfFalse;
    return inv;
}
