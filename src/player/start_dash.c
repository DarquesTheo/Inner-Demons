/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** start_dash
*/

#include "game.h"
#include "player.h"
#include "sound_manager.h"
#include "clock.h"
#include "keybinds.h"

static void set_dash_texture(game_t *game)
{
    sfSprite *player = game->player->sprite;

    if (game->player->dir.x < 0)
            sfSprite_setTexture(player, game->res->player_res->dash_left, 0);
        if (game->player->dir.x > 0)
            sfSprite_setTexture(player, game->res->player_res->dash_right, 0);
        if (game->player->dir.y < 0)
            sfSprite_setTexture(player, game->res->player_res->dash_up, 0);
        if (game->player->dir.y > 0)
            sfSprite_setTexture(player, game->res->player_res->dash_down, 0);
        game->player->rect.left = 0;
        sfSprite_setTextureRect(game->player->sprite, game->player->rect);
}

void start_player_dash(game_t *game)
{
    sfTime time = sfClock_getElapsedTime(game->clocks->player_dash);
    float delta = time.microseconds / 1000000.0;

    if ((game->player->state != DASHING && delta > DASH_CD)
    && (game->info->inputs->player_down || game->info->inputs->player_up
    || game->info->inputs->player_left || game->info->inputs->player_right)) {
        game->player->state = DASHING;
        play_sound(game, "dash", 1);
        game->player->input_dir_vec_on_dash = get_input_dir_vector(game);
        sfClock_restart(game->clocks->player_dash);
        set_dash_texture(game);
    }
}
