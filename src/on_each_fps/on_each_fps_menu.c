/*
** EPITECH PROJECT, 2024
** on_each_fps_menu.c
** File description:
** menu
*/

#include "game.h"
#include "game_menu.h"
#include "menu.h"
#include "sound_manager.h"
#include "clock.h"
#include "player.h"
#include "anim.h"
#include "map.h"
#include "system.h"
#include "res.h"

static void button_pressed_game_menu2(game_t *game, sfVector2f pos)
{
    sfFloatRect hitbox;

    hitbox = sfSprite_getGlobalBounds(game->game_menu->res1_button);
    if (sfFloatRect_contains(&hitbox, pos.x, pos.y) && !game->menu->f_flag) {
        change_resolution(game, 1920, 1080);
        sfRenderWindow_setMouseCursorVisible(game->window, sfFalse);
    }
    hitbox = sfSprite_getGlobalBounds(game->game_menu->res2_button);
    if (sfFloatRect_contains(&hitbox, pos.x, pos.y) && !game->menu->f_flag) {
        change_resolution(game, 1600, 900);
        sfRenderWindow_setMouseCursorVisible(game->window, sfFalse);
    }
    hitbox = sfSprite_getGlobalBounds(game->game_menu->res3_button);
    if (sfFloatRect_contains(&hitbox, pos.x, pos.y) && !game->menu->f_flag) {
        change_resolution(game, 800, 450);
        sfRenderWindow_setMouseCursorVisible(game->window, sfFalse);
    }
}

void button_pressed_game_menu(game_t *game, sfEvent event)
{
    sfFloatRect hitbox;
    sfVector2f pos = (sfVector2f) {event.mouseButton.x, event.mouseButton.y};
    sfVector2u window_size = sfRenderWindow_getSize(game->window);

    pos.x = 100000 + pos.x * 1920 / window_size.x - 960;
    pos.y = 100000 + pos.y * 1080 / window_size.y - 560;
    hitbox = sfSprite_getGlobalBounds(game->game_menu->resume_button);
    if (sfFloatRect_contains(&hitbox, pos.x, pos.y)) {
        game->info->in_menu = !game->info->in_menu;
        game->player->states->can_attack = sfTrue;
        game->player->states->can_move = sfTrue;
    }
    hitbox = sfSprite_getGlobalBounds(game->game_menu->home_button);
    if (sfFloatRect_contains(&hitbox, pos.x, pos.y))
        sfRenderWindow_close(game->window);
    button_pressed_game_menu2(game, pos);
}

void init_button_states2(game_t *game)
{
    sfIntRect rect;
    sfFloatRect hitbox;
    sfBool clicked = sfMouse_isButtonPressed(sfMouseLeft);
    sfVector2f pos = game->info->local_mouse_pos;
    sfVector2u window_size = sfRenderWindow_getSize(game->window);
    sfSprite *sprites[2] = {game->game_menu->home_button,
        game->game_menu->resume_button};

    pos.x = 100000 + pos.x * 1920 / window_size.x - 960;
    pos.y = 100000 + pos.y * 1080 / window_size.y - 560;
    for (int i = 0; i < 2; i++) {
        rect = (sfIntRect) {0, 0, 790, 343};
        hitbox = sfSprite_getGlobalBounds(sprites[i]);
        if (sfFloatRect_contains(&hitbox, pos.x, pos.y) && clicked)
            rect.left = 1580;
        if (sfFloatRect_contains(&hitbox, pos.x, pos.y) && !clicked)
            rect.left = 790;
        sfSprite_setTextureRect(sprites[i], rect);
    }
}

static void handle_game_menu_volume(game_t *game)
{
    sfrenderwindow_drawslider(game->window, game->game_menu->music_slider);
    sfrenderwindow_drawslider(game->window, game->game_menu->sfx_slider);
    sfRenderWindow_drawText(game->window, game->game_menu->music_text, NULL);
    sfRenderWindow_drawText(game->window, game->game_menu->sfx_text, NULL);
    sfRenderWindow_drawText(game->window, game->game_menu->sfx_percent, NULL);
    sfRenderWindow_drawText(game->window, game->game_menu->music_percent,
        NULL);
}

void handle_game_menu(game_t *game)
{
    if (!game->info->in_menu)
        return;
    init_button_states2(game);
    sfRenderWindow_drawRectangleShape
        (game->window, game->game_menu->shade, NULL);
    sfRenderWindow_drawSprite(game->window, game->game_menu->bg, NULL);
    sfRenderWindow_drawSprite
        (game->window, game->game_menu->resume_button, NULL);
    sfRenderWindow_drawSprite
        (game->window, game->game_menu->home_button, NULL);
    sfRenderWindow_drawSprite
        (game->window, game->game_menu->res1_button, NULL);
    sfRenderWindow_drawSprite
        (game->window, game->game_menu->res2_button, NULL);
    sfRenderWindow_drawSprite
        (game->window, game->game_menu->res3_button, NULL);
        handle_game_menu_volume(game);
}
