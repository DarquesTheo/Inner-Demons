/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** interact_draw
*/

#include "interact.h"
#include "game.h"
#include "ui.h"

static void interact_lock_btn(game_t *game)
{
    if (!game->ui->shop->visible)
        button_seticoncolor(game->ui->interact->sell, (sfColor)
            {BLOCKED_BTN_COLOR});
    else
        button_seticoncolor(game->ui->interact->sell, sfWhite);
}

void interact_draw(sfRenderWindow *window, interact_t *menu, game_t *game)
{
    if (!menu->visible)
        return;
    interact_lock_btn(game);
    sfRenderWindow_drawRectangleShape(window, menu->background, NULL);
    sfrenderwindow_drawbutton(window, menu->EquipMainhand);
    sfrenderwindow_drawbutton(window, menu->EquipOffhand);
    sfrenderwindow_drawbutton(window, menu->delete);
    sfrenderwindow_drawbutton(window, menu->sell);
    sfrenderwindow_drawbutton(window, menu->merge);
    sfRenderWindow_drawText(window, menu->itemname, NULL);
}
