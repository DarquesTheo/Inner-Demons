/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** death_menu
*/

#include "ui.h"
#include "game.h"
#include "death.h"

static int get_btn_offset(sfBool clicked, button_t *btn, sfVector2f pos)
{
    if (clicked && is_button_pressed(btn, pos))
        return 1580;
    if (!clicked && is_button_hover(btn, pos))
        return 790;
    if (!is_button_hover(btn, pos))
        return 0;
    return 0;
}

void death_menu_check_click(game_t *game)
{
    sfVector2f pos = game->info->local_mouse_pos;
    sfVector2u window_size = sfRenderWindow_getSize(game->window);

    if (!game->ui->death_menu->active)
        return;
    pos.x = 100000 + pos.x * 1920 / window_size.x - 960;
    pos.y = 100000 + pos.y * 1080 / window_size.y - 560;
    if (is_button_pressed(game->ui->death_menu->restart, pos)) {
        game->ui->death_menu->restart->on_pressed(game);
    }
    if (is_button_pressed(game->ui->death_menu->quit, pos)) {
        game->ui->death_menu->quit->on_pressed(game);
    }
}

void check_death_btn_state(game_t *game)
{
    sfIntRect rect;
    sfBool clicked = sfMouse_isButtonPressed(sfMouseLeft);
    sfVector2f pos = game->info->local_mouse_pos;
    sfVector2u window_size = sfRenderWindow_getSize(game->window);
    button_t *buttons[2] = {game->ui->death_menu->quit,
        game->ui->death_menu->restart};

    if (!game->ui->death_menu->active)
        return;
    pos.x = 100000 + pos.x * 1920 / window_size.x - 960;
    pos.y = 100000 + pos.y * 1080 / window_size.y - 560;
    for (int i = 0; i < 2; i++) {
        rect = (sfIntRect) {0, 0, 790, 343};
        rect.left = get_btn_offset(clicked, buttons[i], pos);
        sfRectangleShape_setTextureRect(buttons[i]->icon, rect);
    }
}

void draw_death_menu(sfRenderWindow *window, death_menu_t *menu)
{
    if (!menu->active)
        return;
    sfRenderWindow_drawRectangleShape(window, menu->bg, NULL);
    sfrenderwindow_drawbutton(window, menu->quit);
    sfrenderwindow_drawbutton(window, menu->restart);
    sfRenderWindow_drawRectangleShape(window, menu->text, NULL);
}
