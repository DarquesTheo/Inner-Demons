/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** sell
*/

#include "interact.h"
#include "ui.h"
#include "utils.h"
#include "player.h"
#include "item.h"

void sell(game_t *game)
{
    if (game->ui == NULL)
        return;
    if (inventory_getslotcontent(game->ui->inventory,
        game->ui->interact->locked_slot) == NULL)
        return;
    player_gain_coin(game, COIN_PER_SALE);
    delete_interact(game);
}
