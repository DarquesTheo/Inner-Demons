/*
** EPITECH PROJECT, 2024
** pattern.c
** File description:
** pattern
*/

#include "anim.h"
#include "enemies.h"
#include "game.h"
#include <stdlib.h>

sfVector2f generate_dir(void)
{
    float nbr = rand() % 101;
    int sign_x = rand() % 2 ? -1 : 1;
    int sign_y = rand() % 2 ? -1 : 1;

    return (sfVector2f) {nbr / 100 * sign_x, (100 - nbr) / 100 * sign_y};
}

sfVector2f mob_random_move2(mob_t *mob, game_t *game, sfVector2f move)
{
    float delta = sfTime_asSeconds(sfClock_getElapsedTime(mob->clock_move))
        * mob->stats->speed;
    sfVector2f dir;

    move = (sfVector2f) {0, 0};
    for (int i = 0; i < 500 && move.x == 0 && move.y == 0; i++) {
        dir = generate_dir();
        move = (sfVector2f) {dir.x * delta, dir.y * delta};
        if (test_hitbox_col_mob(mob, move, game) == 0) {
            mob->pattern->dir = dir;
            mob->pattern->in_pattern = 1;
            sfClock_restart(mob->pattern->clock_move);
            mob->pattern->time = rand() % 2000 + 500;
        }
    }
    if (test_hitbox_col_mob(mob, move, game) != 0)
        move = (sfVector2f) {0, 0};
    return move;
}

void change_shooting_luck(mob_t *mob, float full_distance)
{
    int nbr = rand() % 3;

    if (sfTime_asMilliseconds
        (sfClock_getElapsedTime(mob->pattern->clock_shot)) < 300)
        return;
    sfClock_restart(mob->pattern->clock_shot);
    if (mob->statut != MOVING)
        return;
    if (full_distance > mob->stats->max_range) {
        mob->pattern->luck_shooting += (mob->stats->increase_luck / 3) * nbr;
    } else if (full_distance < mob->stats->min_range) {
        mob->pattern->luck_shooting += (mob->stats->increase_luck / 3) * nbr;
    } else
        mob->pattern->luck_shooting += mob->stats->increase_luck * nbr;
}

sfVector2f mob_random_move(mob_t *mob, game_t *game, sfVector2f move)
{
    float delta = sfTime_asSeconds(sfClock_getElapsedTime(mob->clock_move))
        * mob->stats->speed;

    if (mob->pattern->in_pattern && sfTime_asMilliseconds(
        sfClock_getElapsedTime(mob->pattern->clock_move)) <
        mob->pattern->time) {
        move = (sfVector2f) {mob->pattern->dir.x * delta,
            mob->pattern->dir.y * delta};
        if (test_hitbox_col_mob(mob, move, game) == 0) {
            return move;
        }
    }
    return mob_random_move2(mob, game, move);
}
