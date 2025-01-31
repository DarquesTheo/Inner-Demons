/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** shop_check_event
*/

#include "shop.h"
#include "ui.h"
#include "game.h"

void shop_check_click(game_t *game)
{
    sfVector2f pos = game->info->local_mouse_pos;
    sfVector2u window_size = sfRenderWindow_getSize(game->window);

    if (game->ui == NULL)
        return;
    if (!game->ui->shop->visible)
        return;
    pos.x = 100000 + pos.x * 1920 / window_size.x - 960;
    pos.y = 100000 + pos.y * 1080 / window_size.y - 560;
    if (is_button_pressed(game->ui->shop->health_btn->btn, pos)) {
        game->ui->shop->health_btn->btn->on_pressed(game);
    }
    if (is_button_pressed(game->ui->shop->dream_stone->btn, pos)) {
        game->ui->shop->dream_stone->btn->on_pressed(game);
    }
}
