/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-baptiste.camerlynck
** File description:
** play_game
*/

#include "game.h"
#include "fps.h"
#include "player.h"
#include "anim.h"
#include "enemies.h"

void play_game(game_t *game, sfEvent event)
{
    if (game->player->state == WALKING)
        anim_player(game);
    if (game->player->state == DASHING)
        handle_player_dash(game);
    handle_enemies(game);
    do_fps_clock(game);
    process_game_events(game, event);
}
