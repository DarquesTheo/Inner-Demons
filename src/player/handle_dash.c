/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** player_dash
*/

#include "game.h"
#include "player.h"
#include "res.h"
#include "clock.h"
#include "anim.h"
#include "utils.h"
#include <stdlib.h>

static void dash_smoke(game_t *game, sfVector2f pos)
{
    anim_t *anim = get_default_anim();

    anim->fps = 25;
    anim->img_width = 256;
    anim->duration = 0.25;
    anim->loop = sfTrue;
    sfSprite_setTexture(anim->sprite,
    game->res->obj_res->pot_explosion, 0);
    sfSprite_setOrigin(anim->sprite, (sfVector2f){32, 32});
    sfSprite_setPosition(anim->sprite, pos);
    sfSprite_setScale(anim->sprite, (sfVector2f){1, 1});
    anim->rect = init_intrect(64, 64);
    sfSprite_setTextureRect(anim->sprite, anim->rect);
    anim->move = v2f(0.0f, 0.0f);
    sfSprite_setRotation(anim->sprite, rand() % 360);
    add_anim(game, anim);
}

static void actz_player_dash_sprite(game_t *game)
{
    game->player->rect.left += 64;
    sfClock_restart(game->clocks->player_dash);
    if (game->player->rect.left >= 256) {
        game->player->rect.left = 0;
        game->player->state = WALKING;
        actz_player_anim(game, 1);
        game->player->input_dir_vec_on_dash = (sfVector2f){0, 0};
        return;
    }
    sfSprite_setTextureRect(game->player->sprite, game->player->rect);
}

void handle_player_dash(game_t *game)
{
    sfTime time = sfClock_getElapsedTime(game->clocks->player_dash);
    float delta = time.microseconds / 1000000.0;

    if (delta * 25 > 1) {
        actz_player_dash_sprite(game);
    }
    time = sfClock_getElapsedTime(game->clocks->player_dash_smoke);
    delta = time.microseconds / 1000000.0;
    if (delta * 20 > 1) {
        dash_smoke(game, sfSprite_getPosition(game->player->sprite));
        sfClock_restart(game->clocks->player_dash_smoke);
    }
}
