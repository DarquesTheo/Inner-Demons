/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** slot_applyicon
*/

#include "inventory.h"
#include <stdio.h>
#include "player.h"

void slot_refreshicon(slot_t *slot)
{
    sfTexture *texture = NULL;
    char buff[256];

    if (slot_isempty(slot)) {
        sfText_setString(slot->lvl, "0");
        sfRectangleShape_setFillColor(slot->icon, sfTransparent);
        return;
    }
    texture = ((weapon_t *)(slot->content))->texture;
    if (texture == NULL) {
        sfText_setString(slot->lvl, "0");
        sfRectangleShape_setFillColor(slot->icon, sfTransparent);
        return;
    }
    sprintf(buff, "%d", ((weapon_t *)slot->content)->lvl);
    sfText_setString(slot->lvl, buff);
    sfRectangleShape_setTexture(slot->icon, texture, 1);
    sfRectangleShape_setFillColor(slot->icon, sfWhite);
}
