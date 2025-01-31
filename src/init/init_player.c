/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-baptiste.camerlynck
** File description:
** init_player
*/

#include "player.h"
#include "utils.h"
#include <stdlib.h>

static void init_player2(player_t *player)
{
    player->cam = sfView_createFromRect((sfFloatRect){0, 0, 1920, 1080});
    player->dep_hitbox = create_rect_hitbox(v2f(64, 32), v2f(0, 30));
    player->hitbox = create_rect_hitbox(v2f(50, 80), v2f(0, 0));
    player->input_dir_vec_on_dash = (sfVector2f){0, 0};
    player->coin = 0;
    player->states = malloc(sizeof(pstate_t));
    player->states->can_attack = sfTrue;
    player->states->can_move = sfTrue;
    player->states->can_take_dmg = sfTrue;
    player->states->invincibility = sfClock_create();
}

player_t *init_player(game_t *game)
{
    player_t *player = malloc(sizeof(player_t));

    player->hp = 5;
    player->thp = 5;
    player->level = 1;
    player->rect.height = 68;
    player->rect.width = 66;
    player->rect.top = 0;
    player->rect.left = 0;
    player->sprite = sfSprite_create();
    player->state = WALKING;
    player->wp1 = NULL;
    player->wp2 = NULL;
    sfSprite_setTexture(player->sprite, game->res->player_res->idle_down, 0);
    sfSprite_setOrigin(player->sprite, (sfVector2f){32, 32});
    sfSprite_setScale(player->sprite, (sfVector2f){5, 5});
    sfSprite_setTextureRect(player->sprite, player->rect);
    sfSprite_setPosition(player->sprite, v2f(400, 400));
    init_player2(player);
    return player;
}
