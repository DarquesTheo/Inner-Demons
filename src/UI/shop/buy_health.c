/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** buy_health
*/

#include "shop.h"
#include "game.h"
#include "player.h"
#include "system.h"
#include "ui.h"

void buy_health(game_t *game)
{
    if (game->player->coin < HEALTH_PRICE * game->system->floor)
        return;
    if (game->player->hp == game->player->thp)
        return;
    player_gain_coin(game, -HEALTH_PRICE * game->system->floor);
    player_gain_health(game, HEALTH_AMOUNT);
    shop_refresh_locked(game->ui->shop, game);
}
