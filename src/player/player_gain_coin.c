/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** player_gain_coin
*/

#include "game.h"
#include "player.h"
#include "shop.h"
#include "ui.h"

void player_gain_coin(game_t *game, int amt)
{
    game->player->coin += amt;
    shop_refresh_coin(game->ui->shop, game);
}
