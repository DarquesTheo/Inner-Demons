/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** inventory_toggle
*/

#include "inventory.h"

void inventory_toggle(inventory_t *inv)
{
    inv->active = !inv->active;
}
