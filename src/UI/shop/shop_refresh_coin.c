/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** shop_refresh_coin
*/

#include "game.h"
#include "shop.h"
#include "player.h"
#include <stdio.h>

void shop_refresh_coin(shop_t *shop, game_t *game)
{
    char buff[256];

    sprintf(buff, "%d", game->player->coin);
    sfText_setString(shop->coin_text, buff);
}
