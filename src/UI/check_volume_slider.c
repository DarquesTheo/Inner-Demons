/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** check_volume_slider
*/

#include "game.h"
#include "game_menu.h"
#include "utils.h"
#include "ui.h"
#include <stdio.h>

static void setvolumetext(game_t *game)
{
    char bufsfx[256];
    char bufmusic[256];

    sprintf(bufsfx, "%d%%", game->info->sfx_vol);
    sprintf(bufmusic, "%d%%", game->info->music_vol);
    sfText_setString(game->game_menu->sfx_percent, bufsfx);
    sfText_setString(game->game_menu->music_percent, bufmusic);
}

/* must check if in menu and is clicking before*/
void check_volume_slider(game_t *game)
{
    sfVector2f pos = get_mouse_ui_pos(game);

    pos.y += 20;
    if (game->ui == NULL)
        return;
    if (is_slider_pressed(game->game_menu->sfx_slider, pos)) {
        slider_pressed(game->game_menu->sfx_slider, pos);
    }
    if (is_slider_pressed(game->game_menu->music_slider, pos)) {
        slider_pressed(game->game_menu->music_slider, pos);
    }
    game->info->sfx_vol = slider_getvalue(game->game_menu->sfx_slider) * 100;
    game->info->music_vol = slider_getvalue(game->game_menu->music_slider) *
        100;
    game->info->sfx_vol = (game->info->sfx_vol == 99) ? 100 :
        game->info->sfx_vol;
    game->info->music_vol = (game->info->music_vol == 99) ? 100 :
        game->info->music_vol;
    setvolumetext(game);
}
