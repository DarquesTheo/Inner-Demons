/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** slot_setposition
*/

#include "inventory.h"

void slot_setposition(slot_t *slot, sfVector2f pos)
{
    button_setposition(slot->btn, pos);
    sfRectangleShape_setPosition(slot->icon, (sfVector2f){pos.x +
    SLOT_SIZE_X / 2, pos.y + SLOT_SIZE_Y / 2});
    sfText_setPosition(slot->lvl, (sfVector2f){pos.x + 10, pos.y + 10});
}
