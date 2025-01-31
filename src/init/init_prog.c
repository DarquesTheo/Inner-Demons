/*
** EPITECH PROJECT, 2024
** RPG
** File description:
** init_game
*/

#include "game.h"
#include "map.h"
#include "res.h"
#include "menu.h"
#include "clock.h"
#include "ui.h"
#include "player.h"
#include "enemies.h"
#include "system.h"
#include <stdlib.h>
#include "game_menu.h"
#include "objects.h"
#include "utils.h"

game_t *init_prog(int f_flag)
{
    game_t *game = malloc(sizeof(game_t));

    game->res = init_res();
    game->res->mob = init_mobs_struct();
    init_sbufs(game);
    init_tex_list(game);
    game->menu = init_menu(game);
    game->window = init_window(f_flag);
    game->info = init_game_info(game);
    game->clocks = NULL;
    game->info->game_status = MAIN_MENU;
    game->game_menu = init_game_menu();
    game->map = NULL;
    game->player = NULL;
    game->anims = NULL;
    game->sound_manager = NULL;
    game->ui = NULL;
    game->system = NULL;
    game->dialogue = NULL;
    return game;
}
