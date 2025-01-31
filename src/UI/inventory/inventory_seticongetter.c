/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** inventory_seticongetter
*/

#include "inventory.h"

void inventory_seticongetter(inventory_t *inv, sfTexture *(*geticon)(void *))
{
    inv->geticon = geticon;
}
