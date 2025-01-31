/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** refresh_interact_name
*/

#include "game.h"
#include "player.h"
#include "ui.h"
#include "interact.h"

void refresh_interact_name(game_t *game)
{
    weapon_t *wp = NULL;

    if (game->ui == NULL)
        return;
    wp = inventory_getslotcontent(game->ui->inventory,
        (sfVector2i){LOCKED_POS});
    wp = inventory_getslotcontent(game->ui->inventory,
        (sfVector2i){LOCKED_POS});
    if (wp == NULL) {
        sfText_setString(INTERACT->itemname, "empty");
        return;
    }
    sfText_setString(INTERACT->itemname, wp->name);
}
