/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** shop_toggle
*/

#include "shop.h"
#include "game.h"
#include "system.h"
#include <stdio.h>
#include <string.h>

void shop_toggle(shop_t *shop, game_t *game)
{
    char buf[256];

    sprintf(buf, "for %d", HEALTH_PRICE * game->system->floor);
    sfText_setString(shop->health_btn->price, buf);
    shop->visible = !shop->visible;
    shop_refresh_locked(shop, game);
}
