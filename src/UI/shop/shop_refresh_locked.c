/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** shop_refresh_locked
*/

#include "game.h"
#include "ui.h"
#include "shop.h"
#include "interact.h"
#include "player.h"
#include "system.h"

void shop_refresh_locked(shop_t *shop, game_t *game)
{
    if (game->player->hp == game->player->thp ||
        game->player->coin < HEALTH_PRICE * game->system->floor)
        button_seticoncolor(shop->health_btn->btn, (sfColor)
            {BLOCKED_BTN_COLOR});
    else
        button_seticoncolor(shop->health_btn->btn, sfWhite);
}
