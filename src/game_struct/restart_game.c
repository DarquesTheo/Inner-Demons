/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** restart_game
*/

#include "game.h"

void go_home(game_t *game)
{
    free_game_not_res_or_window(game);
    game->info->game_status = MAIN_MENU;
    sfRenderWindow_setMouseCursorVisible(game->window, sfTrue);
    sfRenderWindow_setView(game->window, sfView_createFromRect((sfFloatRect)
        {0, 0, 1920, 1080}));
}

void restart_game(game_t *game)
{
    free_game_not_res_or_window(game);
    start_game(game);
}
