/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** start_game
*/

#include "game.h"
#include "player.h"
#include "system.h"
#include "clock.h"
#include "ui.h"
#include "dialogue.h"
#include "objects.h"
#include "utils.h"

void start_game(game_t *game)
{
    game->player = init_player(game);
    game->clocks = init_clocks();
    game->ui = init_ui(game->res);
    heart_refresh(game->ui->heart, game);
    init_system(game);
    game->info->game_status = GAME;
    sfRenderWindow_setMouseCursorVisible(game->window, sfFalse);
    sfRenderWindow_setView(game->window, game->player->cam);
}
