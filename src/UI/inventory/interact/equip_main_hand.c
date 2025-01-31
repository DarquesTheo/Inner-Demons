/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** equip_main_hand
*/

#include "interact.h"
#include "ui.h"
#include "utils.h"
#include "player.h"
#include "item.h"

void equip_mainhand(game_t *game)
{
    weapon_t *weapon_hand = NULL;
    weapon_t *weapon_slot = NULL;

    if (game->ui == NULL)
        return;
    weapon_hand = game->player->wp1;
    weapon_slot = inventory_getslotcontent(game->ui->inventory,
        game->ui->interact->locked_slot);
    game->player->wp1 = weapon_slot;
    inventory_insertitem(game->ui->inventory, weapon_hand,
        game->ui->interact->locked_slot);
}
