/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** interact_button_event
*/

#include "interact.h"
#include "ui.h"
#include "utils.h"

void interact_button_event_click(game_t *game)
{
    sfVector2f pos = get_mouse_ui_pos(game);

    if (game->ui == NULL)
        return;
    if (!game->ui->interact->visible || !game->ui->interact->locked)
        return;
    if (is_button_pressed(game->ui->interact->EquipMainhand, pos))
        game->ui->interact->EquipMainhand->on_pressed(game);
    if (is_button_pressed(game->ui->interact->EquipOffhand, pos))
        game->ui->interact->EquipOffhand->on_pressed(game);
    if (is_button_pressed(game->ui->interact->delete, pos))
        game->ui->interact->delete->on_pressed(game);
    if (game->ui->shop->visible && is_button_pressed(game->ui->interact->sell,
        pos))
        game->ui->interact->sell->on_pressed(game);
    if (game->ui->shop->visible && is_button_pressed(game->ui->interact->merge,
        pos))
        game->ui->interact->merge->on_pressed(game);
}
