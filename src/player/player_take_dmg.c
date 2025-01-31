/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** player_take_dmg
*/

#include "game.h"
#include "const.h"
#include "player.h"
#include "ui.h"
#include "sound_manager.h"
#include "utils.h"

void player_take_dmg2(game_t *game)
{
    play_sound(game, "player_take_dmg", 1);
    play_sound(game, "player_hurt", rand_float(0.9, 1));
    heart_refresh(game->ui->heart, game);
    if (game->player->hp <= 0) {
        game->ui->death_menu->active = sfTrue;
        game->player->states->can_take_dmg = sfFalse;
        play_sound(game, "lose1", 1);
    }
}

void player_take_dmg(game_t *game, float dmg)
{
    sfColor invicible = {255, 255, 255, 100};

    if (game->player->states->can_take_dmg == sfFalse || (rand() % 100) + 1 <=
    (get_multiplicator_stat(DODGE, game) - 1) * 100)
        return;
    if (game->player->hp > game->player->thp)
        game->player->hp = game->player->thp;
    game->player->states->can_take_dmg = sfFalse;
    sfSprite_setColor(game->player->sprite, invicible);
    if (game->player->wp1)
        sfSprite_setColor(game->player->wp1->sprite, invicible);
    if (game->player->wp1)
        sfSprite_setColor(game->player->wp2->sprite, invicible);
    sfClock_restart(game->player->states->invincibility);
    game->player->hp -= dmg;
    player_take_dmg2(game);
}
