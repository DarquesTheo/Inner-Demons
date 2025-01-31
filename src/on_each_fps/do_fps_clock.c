/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** do_fps_clock
*/

#include "game.h"
#include "fps.h"
#include "clock.h"
#include "player.h"
#include "anim.h"
#include "player.h"
#include "enemies.h"
#include "system.h"

static void do_fps_clock2(game_t *game)
{
    on_each_fps_ui(game);
    sfRenderWindow_setView(game->window, game->player->cam);
    on_each_fps_cursor(game);
    sfRenderWindow_display(game->window);
}

void do_fps_clock(game_t *game)
{
    sfTime time = sfClock_getElapsedTime(game->clocks->fps);
    float delta = time.microseconds / 1000000.0;

    if (delta * game->info->fps > 1) {
        sfClock_restart(game->clocks->fps);
        sfRenderWindow_clear(game->window, sfBlack);
        sfRenderWindow_setView(game->window, game->player->cam);
        handle_system(game);
        on_each_fps_sound_manager(game);
        on_each_fps_room(game);
        anim_list(game);
        on_each_fps_anim_list(game, delta, 1);
        draw_spawn_enemies(game);
        draw_enemies(game);
        on_each_fps_player(game, delta);
        on_each_fps_anim_list(game, delta, 2);
        do_fps_clock2(game);
    }
}
