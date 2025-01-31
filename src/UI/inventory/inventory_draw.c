/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** inventory_draw
*/

#include "inventory.h"

void sfrenderwindow_drawinventory(sfRenderWindow *window, inventory_t *inv)
{
    if (!inv->active)
        return;
    for (int i = 0; inv->inv[i] != NULL; i++) {
        for (int j = 0; inv->inv[i][j] != NULL; j++) {
            sfrenderwindow_drawslot(window, inv->inv[i][j]);
        }
    }
}
