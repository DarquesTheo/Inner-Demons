/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** player_anim_mouse
*/

#include "game.h"
#include "const.h"
#include "utils.h"
#include "player.h"
#include "res.h"

void player_anim_on_mouse_move(game_t *game, int mouse_side)
{
    sfSprite *player = game->player->sprite;

    switch (mouse_side) {
        case LEFT:
            sfSprite_setTexture(player, game->res->player_res->move_left, 0);
            break;
        case RIGHT :
            sfSprite_setTexture(player, game->res->player_res->move_right, 0);
            break;
        case TOP:
            sfSprite_setTexture(player, game->res->player_res->move_up, 0);
            break;
        case BOTTOM:
            sfSprite_setTexture(player, game->res->player_res->move_down, 0);
            break;
    }
}

void player_anim_idle(game_t *game, int mouse_side)
{
    sfSprite *player = game->player->sprite;

    switch (mouse_side) {
        case LEFT:
            sfSprite_setTexture(player, game->res->player_res->idle_left, 0);
            break;
        case RIGHT :
            sfSprite_setTexture(player, game->res->player_res->idle_right, 0);
            break;
        case TOP:
            sfSprite_setTexture(player, game->res->player_res->idle_up, 0);
            break;
        case BOTTOM:
            sfSprite_setTexture(player, game->res->player_res->idle_down, 0);
            break;
    }
}

void actz_player_anim(game_t *game, int is_new_dir)
{
    sfVector2u wsize = sfRenderWindow_getSize(game->window);
    int mouse_side =
    get_point_pos_in_rectangle(game->info->local_mouse_pos,
    v2f(wsize.x, wsize.y));
    int last_mouse_side =
    get_point_pos_in_rectangle(game->info->last_local_mouse_pos,
    v2f(wsize.x, wsize.y));
    sfVector2f player_dir = get_player_delta_vector(game, 1);

    if (mouse_side != last_mouse_side || is_new_dir) {
        if (player_dir.x == 0 && player_dir.y == 0) {
            player_anim_idle(game, mouse_side);
        } else {
            player_anim_on_mouse_move(game, mouse_side);
        }
    }
}
