/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** get_player_vector and actualize the direction of the sprite if needed
*/

#include "game.h"
#include "vector.h"
#include "player.h"
#include "res.h"
#include "keybinds.h"
#include "artefact.h"


void set_player_idle(game_t *game)
{
    sfSprite *player = game->player->sprite;

    if (game->player->dir.x < 0)
        sfSprite_setTexture(player, game->res->player_res->idle_left, 0);
    if (game->player->dir.x > 0)
        sfSprite_setTexture(player, game->res->player_res->idle_right, 0);
    if (game->player->dir.y < 0) {
        sfSprite_setTexture(player, game->res->player_res->idle_up, 0);
    } else if (game->player->dir.y > 0) {
        sfSprite_setTexture(player, game->res->player_res->idle_down, 0);
    }
    game->player->rect.left = 0;
    sfSprite_setTextureRect(game->player->sprite, game->player->rect);
}

void set_player_sprite(game_t *game, sfVector2f dir)
{
    sfSprite *player = game->player->sprite;

    if (dir.x < 0)
        sfSprite_setTexture(player, game->res->player_res->move_left, 0);
    if (dir.x > 0)
        sfSprite_setTexture(player, game->res->player_res->move_right, 0);
    if (dir.y < 0) {
        sfSprite_setTexture(player, game->res->player_res->move_up, 0);
    } else if (dir.y > 0) {
        sfSprite_setTexture(player, game->res->player_res->move_down, 0);
    }
    game->player->rect.left = 0;
    sfSprite_setTextureRect(game->player->sprite, game->player->rect);
}

//vector isn't normalized
sfVector2f get_input_dir_vector(game_t *game)
{
    sfVector2f vec = {0, 0};

    if (game->info->inputs->player_up)
        vec.y -= 1;
    if (game->info->inputs->player_down)
        vec.y += 1;
    if (game->info->inputs->player_left)
        vec.x -= 1;
    if (game->info->inputs->player_right)
        vec.x += 1;
    return vec;
}

sfVector2f get_player_delta_vector(game_t *game, float delta)
{
    sfVector2f vec;
    float speed = get_player_speed(game);

    if (game->player->state == DASHING) {
        vec = game->player->input_dir_vec_on_dash;
    } else {
        vec = get_input_dir_vector(game);
    }
    vec = normalize_vector(vec);
    game->player->dir = vec;
    vec.x *= delta * speed * get_multiplicator_stat(MOVEMENT_SPEED, game);
    vec.y *= delta * speed * get_multiplicator_stat(MOVEMENT_SPEED, game);
    return vec;
}
