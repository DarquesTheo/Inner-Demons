/*
** EPITECH PROJECT, 2024
** enemies_moves.c
** File description:
** enemies movements functions
*/

#include "enemies.h"
#include "game.h"
#include "math.h"
#include "player.h"
#include "vector.h"
#include "utils.h"
#include "map.h"
#include "anim.h"
#include <stdlib.h>

static sfVector2f test_new_move_to_escape(sfVector2f move_init, int i)
{
    sfVector2f move = {0, 0};
    sfVector2f vectors[4] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    float full_distance = fabs(move_init.x) + fabs(move_init.y);

    move.x = vectors[i].x * full_distance;
    move.y = vectors[i].y * full_distance;
    return move;
}

static int test_vector_to_player(sfVector2f pos, game_t *game, sfVector2f move)
{
    sfVector2f fictional_pos = add_vectors(pos, move);
    sfVector2f fictional_vector = get_vector_difference(fictional_pos,
        sfSprite_getPosition(game->player->sprite));
    sfVector2f actual_vector = get_vector_difference(pos,
        sfSprite_getPosition(game->player->sprite));

    if (fabs(fictional_vector.x) + fabs(fictional_vector.y) >
        fabs(actual_vector.x) + fabs(actual_vector.y)) {
        return 0;
    }
    return 1;
}

int test_hitbox_col_mob(mob_t *mob, sfVector2f move,
    game_t *game)
{
    sfRectangleShape *hitbox = sfRectangleShape_copy(mob->hitbox->rect);
    sfVector2f *rect_point_list = get_rectangle_points(8, hitbox);
    sfVector2f deplacement;

    for (int i = 0; i < 32; i++) {
        deplacement = add_vectors(rect_point_list[i], move);
        if (get_tile_point_col(game, deplacement) != 0) {
            free(rect_point_list);
            sfRectangleShape_destroy(hitbox);
            return 1;
        }
    }
    free(rect_point_list);
    sfRectangleShape_destroy(hitbox);
    return 0;
}

sfVector2f mob_escape(mob_t *mob, game_t *game,
    sfVector2f move, float full_distance)
{
    float delta = sfTime_asSeconds(sfClock_getElapsedTime(mob->clock_move))
        * mob->stats->speed;
    sfVector2f move_init = (sfVector2f) {0, 0};
    int i = 0;

    if (full_distance != 0) {
        move_init.x = -(move.x / full_distance * delta);
        move_init.y = -(move.y / full_distance * delta);
        move = move_init;
        while ((test_hitbox_col_mob(mob, move, game) != 0 ||
            test_vector_to_player(mob->pos, game, move)) && i < 4) {
            move = test_new_move_to_escape(move_init, i);
            i++;
        }
        if (test_hitbox_col_mob(mob, move, game) != 0)
            move = (sfVector2f) {0, 0};
        move_init = move;
    }
    return move_init;
}

sfVector2f mob_chase(mob_t *mob, sfVector2f move,
    float full_distance, game_t *game)
{
    float delta = sfTime_asSeconds(sfClock_getElapsedTime(mob->clock_move))
        * mob->stats->speed;
    sfVector2f move_init = (sfVector2f) {0, 0};
    int i = 0;

    if (full_distance != 0) {
        move_init.x = move.x / full_distance * delta;
        move_init.y = move.y / full_distance * delta;
        move = move_init;
        while ((test_hitbox_col_mob(mob, move, game) != 0 ||
            !test_vector_to_player(mob->pos, game, move)) && i < 4) {
            move = test_new_move_to_escape(move_init, i);
            i++;
        }
        if (test_hitbox_col_mob(mob, move, game) != 0) {
            move = (sfVector2f) {0, 0};
        }
        move_init = move;
    }
    return move_init;
}

sfVector2f get_next_move_mob(mob_t *mob, game_t *game)
{
    sfVector2f move = get_vector_difference(mob->pos,
        sfSprite_getPosition(game->player->sprite));
    float full_distance = fabs(move.x) + fabs(move.y);

    change_shooting_luck(mob, full_distance);
    if (full_distance > mob->stats->max_range) {
        move = mob_chase(mob, move, full_distance, game);
        mob->pattern->in_pattern = 0;
    } else if (full_distance < mob->stats->min_range) {
        move = mob_escape(mob, game, move, full_distance);
        mob->pattern->in_pattern = 0;
    } else
        move = mob_random_move(mob, game, move);
    sfClock_restart(mob->clock_move);
    return move;
}

void move_mob(mob_t *mob, game_t *game)
{
    sfVector2f move = get_next_move_mob(mob, game);
    sfVector2f diff_with_player = get_vector_difference(mob->pos,
        sfSprite_getPosition(game->player->sprite));

    mob->pos = add_vectors(mob->pos, move);
    if (move.x < 0)
        sfSprite_setScale(mob->sprite, (sfVector2f) {-1, 1});
    else
        sfSprite_setScale(mob->sprite, (sfVector2f) {1, 1});
    if (mob->statut == ATTACKING || mob->statut == ATTACKING2) {
        if (diff_with_player.x < 0)
            sfSprite_setScale(mob->sprite, (sfVector2f) {-1, 1});
        else
            sfSprite_setScale(mob->sprite, (sfVector2f) {1, 1});
    }
}
