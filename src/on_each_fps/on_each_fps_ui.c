/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** on_each_fps_ui
*/

#include "game.h"
#include "player.h"
#include "ui.h"
#include "game_menu.h"
#include "inventory.h"
#include "shop.h"
#include "heart.h"
#include "dialogue.h"
#include "artefact.h"

void check_player_states_ui(game_t *game)
{
    if (game->info->in_menu || game->ui->artefact->visible ||
        game->ui->shop->visible || game->ui->death_menu->active) {
        game->player->states->can_attack = sfFalse;
        game->player->states->can_move = sfFalse;
    } else {
        game->player->states->can_attack = sfTrue;
        game->player->states->can_move = sfTrue;
    }
}

void on_each_fps_ui(game_t *game)
{
    sfRenderWindow_setView(game->window, game->ui->view);
    sfrenderwindow_drawshop(game->window, game->ui->shop);
    sfrenderwindow_drawheart(game->window, game->ui->heart);
    draw_exp_bar(game);
    draw_boss_bar(game);
    draw_artefact_ui(game->window, game->ui->artefact, game);
    sfrenderwindow_drawinventory(game->window, game->ui->inventory);
    if (game->ui->inventory->active)
        interact_draw(game->window, game->ui->interact, game);
    draw_dialogue(game);
    draw_coin(game->window, game->ui->shop);
    check_death_btn_state(game);
    draw_death_menu(game->window, game->ui->death_menu);
    handle_game_menu(game);
    check_player_states_ui(game);
}
