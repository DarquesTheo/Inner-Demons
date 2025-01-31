/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** slot_draw
*/

#include "inventory.h"

void sfrenderwindow_drawslot(sfRenderWindow *window, slot_t *slot)
{
    sfrenderwindow_drawbutton(window, slot->btn);
    sfRenderWindow_drawRectangleShape(window, slot->icon, NULL);
    sfRenderWindow_drawText(window, slot->lvl, NULL);
}
