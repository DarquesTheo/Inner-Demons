/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** mouse_in_inventory
*/

#include "inventory.h"
#include "utils.h"
#include "ui.h"

sfBool is_mouse_in_inventory(game_t *game)
{
    sfVector2f pos = get_mouse_ui_pos(game);

    if (game->ui == NULL)
        return sfFalse;
    if (!game->ui->inventory->active)
        return sfFalse;
    if (100610 < pos.x)
        return sfTrue;
    return sfFalse;
}
