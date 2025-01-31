/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-baptiste.camerlynck
** File description:
** player_events
*/

#include "game.h"
#include "keybinds.h"
#include "player.h"
#include "inventory.h"
#include "system.h"
#include "ui.h"
#include <stdio.h>

void print_movement_inputs(inputs_t *inputs)
{
    printf("%d ", inputs->player_up);
    printf("%d ", inputs->player_down);
    printf("%d ", inputs->player_right);
    printf("%d\n", inputs->player_left);
    printf("%d\n ", inputs->toggle_shop);
}

//return true if the actual and the last move inputs are the same
static int is_same_player_movement(game_t *game)
{
    inputs_t *input1 = game->info->inputs;
    inputs_t *input2 = game->info->last_inputs;

    if (input1->player_up != input2->player_up)
        return 0;
    if (input1->player_down != input2->player_down)
        return 0;
    if (input1->player_left != input2->player_left)
        return 0;
    if (input1->player_right != input2->player_right)
        return 0;
    return 1;
}

static void player_event_pressed_other(game_t *game, sfEvent *event)
{
    if (event->key.code == sfKeyEscape) {
        artefact_tryclose(game);
    }
}

static void player_event_pressed(game_t *game, sfEvent *event)
{
    if (event->key.code == game->info->keybinds->player_up)
        game->info->inputs->player_up = 1;
    if (event->key.code == game->info->keybinds->player_down)
        game->info->inputs->player_down = 1;
    if (event->key.code == game->info->keybinds->player_left)
        game->info->inputs->player_left = 1;
    if (event->key.code == game->info->keybinds->player_right)
        game->info->inputs->player_right = 1;
    if (event->key.code == game->info->keybinds->toggle_shop)
        game->info->inputs->toggle_shop = 1;
    if (event->key.code == game->info->keybinds->player_dash)
        start_player_dash(game);
    if (event->key.code == game->info->keybinds->toggle_inventory)
        inventory_toggle(game->ui->inventory);
    player_event_pressed_other(game, event);
}

static void player_event_released(game_t *game, sfEvent *event)
{
    if (event->key.code == game->info->keybinds->player_up)
        game->info->inputs->player_up = 0;
    if (event->key.code == game->info->keybinds->player_down)
        game->info->inputs->player_down = 0;
    if (event->key.code == game->info->keybinds->player_left)
        game->info->inputs->player_left = 0;
    if (event->key.code == game->info->keybinds->player_right)
        game->info->inputs->player_right = 0;
    if (event->key.code == game->info->keybinds->toggle_shop)
        game->info->inputs->toggle_shop = 0;
}

static void act_last_input(game_t *game)
{
    game->info->last_inputs->player_down = game->info->inputs->player_down;
    game->info->last_inputs->player_up = game->info->inputs->player_up;
    game->info->last_inputs->player_left = game->info->inputs->player_left;
    game->info->last_inputs->player_right = game->info->inputs->player_right;
    game->info->last_inputs->toggle_shop = game->info->inputs->toggle_shop;
}

static void reset_inputs(game_t *game)
{
    game->info->inputs->player_down = 0;
    game->info->inputs->player_up = 0;
    game->info->inputs->player_left = 0;
    game->info->inputs->player_right = 0;
}

void player_events(game_t *game, sfEvent *event)
{
    if (event->type == sfEvtKeyPressed || event->type == sfEvtKeyReleased) {
        act_last_input(game);
        if (event->type == sfEvtKeyPressed) {
            player_event_pressed(game, event);
        }
        if (event->type == sfEvtKeyReleased) {
            player_event_released(game, event);
        }
        if (game->player->states->can_move == sfFalse
        || game->dialogue != NULL)
            reset_inputs(game);
        if (!is_same_player_movement(game) && game->player->state != DASHING) {
            actz_player_anim(game, 1);
        }
    }
}
