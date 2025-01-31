/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** player_gain_health
*/

#include "game.h"
#include "const.h"
#include "player.h"
#include "ui.h"
#include "sound_manager.h"

void player_gain_health(game_t *game, float amt)
{
    game->player->hp += amt;
    if (game->player->hp > game->player->thp)
        game->player->hp = game->player->thp;
    heart_refresh(game->ui->heart, game);
}
