/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** interact_event
*/

#include "interact.h"
#include "game.h"
#include "inventory.h"
#include "ui.h"
#include "button.h"
#include "shop.h"
#include "utils.h"

void check_slot_hover(slot_t *slot, sfVector2f pos, sfBool *active)
{
    if (is_button_hover(slot->btn, pos)) {
        *active = sfTrue;
    }
}

void check_slot_clicked(slot_t *slot, sfVector2f pos, game_t *game,
    sfBool *active)
{
    if (is_button_hover(slot->btn, pos)) {
        game->ui->interact->locked = sfTrue;
        *active = sfTrue;
        interact_menu_setpos(game->ui->interact, (sfVector2f){pos.x -
                INTERACT_MENU_SIZE_X, pos.y});
    }
}

static void interact_check(game_t *game, sfVector2f pos)
{
    if (is_in_rectangle(game->ui->interact->background, pos) &&
        game->ui->interact->locked)
        game->ui->interact->visible = sfTrue;
    if (!game->ui->interact->visible &&
        !is_in_rectangle(game->ui->interact->background, pos))
        game->ui->interact->locked = sfFalse;
    if (game->ui->interact->visible == sfFalse)
        interact_menu_setpos(game->ui->interact, (sfVector2f){0, 0});
}

void interact_event_hover(game_t *game)
{
    inventory_t *inv = game->ui->inventory;
    sfVector2f pos = game->info->local_mouse_pos;
    sfVector2u window_size = sfRenderWindow_getSize(game->window);
    sfBool active = sfFalse;

    if (!inv->active)
        return;
    pos.x = 100000 + pos.x * 1920 / window_size.x - 960;
    pos.y = 100000 + pos.y * 1080 / window_size.y - 560;
    for (int i = 0; i < inv->size_y; i++) {
        for (int j = 0; j < inv->size_x; j++) {
            check_slot_hover(inv->inv[i][j], pos, &active);
        }
    }
    game->ui->interact->visible = active;
    interact_check(game, pos);
}

static void interact_event_clicked_line(game_t *game, sfVector2f pos,
    int i, sfBool *active)
{
    inventory_t *inv = game->ui->inventory;
    sfBool was_active = *active;

    if (is_in_rectangle(game->ui->interact->background, pos) &&
        game->ui->interact->locked)
        return;
    for (int j = 0; j < inv->size_x; j++) {
        check_slot_clicked(inv->inv[i][j], pos, game, active);
        if (!was_active && *active)
            game->ui->interact->locked_slot = (sfVector2i){j, i};
        was_active = *active;
    }
}

void interact_event_clicked(game_t *game)
{
    inventory_t *inv;
    sfVector2f pos = get_mouse_ui_pos(game);
    sfBool active = sfFalse;

    if (game->ui == NULL)
        return;
    inv = game->ui->inventory;
    if (!inv->active)
        return;
    for (int i = 0; i < inv->size_y; i++) {
        interact_event_clicked_line(game, pos, i, &active);
    }
    if (!active)
        return;
    if (can_merge(game) && game->ui->shop->visible)
        button_seticoncolor(game->ui->interact->merge, sfWhite);
    else
        button_seticoncolor(game->ui->interact->merge,
            (sfColor){BLOCKED_BTN_COLOR});
    refresh_interact_name(game);
}
