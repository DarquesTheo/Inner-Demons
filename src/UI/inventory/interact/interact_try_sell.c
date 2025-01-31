/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** interact_try_sell
*/

#include "interact.h"
#include "game.h"
#include "inventory.h"
#include "ui.h"
#include "button.h"
#include "utils.h"
#include "player.h"

static void interact_try_sell_line(game_t *game, sfVector2f pos,
    int i)
{
    inventory_t *inv = game->ui->inventory;

    for (int j = 0; j < inv->size_x; j++) {
        if (is_button_pressed(inv->inv[i][j]->btn, pos)) {
            game->ui->interact->locked_slot = (sfVector2i){j, i};
            game->ui->interact->locked = sfFalse;
            sell(game);
        }
    }
}

void interact_try_sell(game_t *game)
{
    sfVector2f pos = get_mouse_ui_pos(game);

    if (game->ui == NULL)
        return;
    if (!game->ui->inventory->active)
        return;
    if (!game->ui->shop->visible)
        return;
    for (int i = 0; i < game->ui->inventory->size_y; i++) {
        interact_try_sell_line(game, pos, i);
    }
}
