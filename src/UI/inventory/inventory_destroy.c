/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** inventory_destroy
*/

#include "inventory.h"
#include "button.h"

void slot_destroy(slot_t *slot, void(*freefnc)(void *))
{
    if (slot == NULL || freefnc == NULL)
        return;
    destroy_button(slot->btn);
    sfRectangleShape_destroy(slot->icon);
    if (slot->content != NULL)
        freefnc(slot->content);
    free(slot);
}

void inventory_destroy(inventory_t *inv, void(*freefnc)(void *))
{
    for (int i = 0; i < inv->size_y; i++) {
        for (int j = 0; j < inv->size_x; j++) {
            slot_destroy(inv->inv[i][j], freefnc);
        }
    }
    free(inv);
}
