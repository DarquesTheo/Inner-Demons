/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** event
*/

#include "game.h"
#include "keybinds.h"
#include "utils.h"
#include "player.h"
#include "game_menu.h"
#include <string.h>
#include "dialogue.h"
#include "shop.h"
#include "interact.h"

static void key_pressed(game_t *game, sfEvent event)
{
    if (event.key.code == sfKeyM)
        game->info->debug = 1 - game->info->debug;
    if (event.key.code == sfKeyEscape) {
        game->info->in_menu = !game->info->in_menu;
    }
}

static void mouse_button_pressed(game_t *game, sfEvent event)
{
    if (game->dialogue)
        return skip_dialogue(game);
    if (event.mouseButton.button == sfMouseLeft) {
        game->info->mouse->left_click = 1;
    }
    if (event.mouseButton.button == sfMouseRight) {
        game->info->mouse->right_click = 1;
    }
}

static void mouse_button_released(game_t *game, sfEvent event)
{
    if (event.mouseButton.button == sfMouseLeft) {
        game->info->mouse->left_click = 0;
        if (game->info->in_menu)
            button_pressed_game_menu(game, event);
        death_menu_check_click(game);
        shop_check_click(game);
        interact_button_event_click(game);
        interact_event_clicked(game);
    }
    if (event.mouseButton.button == sfMouseRight) {
        game->info->mouse->right_click = 0;
        interact_try_sell(game);
    }
}

static void update_weapon_transform2(game_t *game, weapon_t *wp)
{
    sfVector2u wsize = sfRenderWindow_getSize(game->window);
    sfVector2f sc = sfSprite_getScale(wp->sprite);

    if (get_point_side_in_rectangle(game->info->local_mouse_pos,
    v2f(wsize.x, wsize.y)) == RIGHT) {
        if (sc.y < 0)
            sfSprite_setScale(wp->sprite, v2f(sc.x, -sc.y));
    } else {
        if (sc.y > 0)
            sfSprite_setScale(wp->sprite, v2f(sc.x, -sc.y));
    }
}

static void update_weapon_transform(game_t *game)
{
    if (game->player->wp1) {
        update_weapon_transform2(game, game->player->wp1);
        look_at(game->player->wp1->sprite, game->info->mouse_pos,
        game->player->wp1->angle_offset);
    }
    if (game->player->wp2) {
        update_weapon_transform2(game, game->player->wp2);
        look_at(game->player->wp2->sprite, game->info->mouse_pos,
        game->player->wp2->angle_offset);
    }
}

static void mouse_moved(game_t *game)
{
    sfVector2u wsize = sfRenderWindow_getSize(game->window);
    int mouse_side = get_point_pos_in_rectangle(game->info->local_mouse_pos,
    v2f(wsize.x, wsize.y));

    if (mouse_side != OUT)
        game->info->mouse_side = mouse_side;
    if (game->player->state != DASHING)
        actz_player_anim(game, 1);
    update_weapon_transform(game);
    interact_event_hover(game);
    if (game->info->in_menu && sfMouse_isButtonPressed(sfMouseLeft))
        check_volume_slider(game);
}

void process_game_events(game_t *game, sfEvent event)
{
    while (sfRenderWindow_pollEvent(game->window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(game->window);
        }
        if (event.type == sfEvtMouseButtonPressed) {
            mouse_button_pressed(game, event);
        }
        if (event.type == sfEvtMouseMoved) {
            mouse_moved(game);
        }
        if (event.type == sfEvtMouseButtonReleased) {
            mouse_button_released(game, event);
        }
        if (game->info->game_status == MAIN_MENU)
            return;
        if (event.type == sfEvtKeyPressed) {
            key_pressed(game, event);
        }
        player_events(game, &event);
    }
}
