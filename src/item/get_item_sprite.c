/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** get_item_sprite
*/

#include "item.h"
#include "player.h"

sfSprite *get_item_sprite(item_t *item)
{
    if (item->type == WEAPON)
        return ((weapon_t *)(item->obj))->sprite;
    return NULL;
}
