/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** player_anim
*/

#include "game.h"
#include "player.h"
#include "clock.h"

static void anim_playerr(game_t *game)
{
    game->player->rect.left += 64;
    if (game->player->rect.left >= 384) {
        game->player->rect.left = 0;
    }
    sfSprite_setTextureRect(game->player->sprite, game->player->rect);
}

void anim_player(game_t *game)
{
    sfTime time = sfClock_getElapsedTime(game->clocks->player_anim);
    float delta = time.microseconds / 1000000.0;

    if (delta * 8 > 1) {
        anim_playerr(game);
        sfClock_restart(game->clocks->player_anim);
    }
}
