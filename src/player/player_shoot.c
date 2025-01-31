/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** player_shoot
*/

#include "game.h"
#include "player.h"
#include "keybinds.h"
#include "artefact.h"

void check_weapon_cd_and_shoot(game_t *game, weapon_t *wp)
{
    sfTime time = sfClock_getElapsedTime(wp->clock);
    float delta = time.microseconds / 1000000.0;

    if (delta * wp->fire_rate *
    get_multiplicator_stat(ATTACK_SPEED, game) > 1) {
        wp->shoot(game, wp);
        sfClock_restart(wp->clock);
    }
}

void player_shoot(game_t *game)
{
    if ((game->player->state != DASHING && game->player->states->can_attack)
        && !is_mouse_in_inventory(game)) {
        if (game->info->mouse->left_click && game->player->wp1)
            check_weapon_cd_and_shoot(game, game->player->wp1);
        if (game->info->mouse->right_click && game->player->wp2)
            check_weapon_cd_and_shoot(game, game->player->wp2);
    }
}
