/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** spawn_random_money
*/

#include "game.h"
#include "objects.h"
#include <stdlib.h>
#include "artefact.h"
#include "utils.h"
#include "const.h"
#include "vector.h"
#include <math.h>

void spawn_random_money(game_t *game, sfVector2f pos, sfBool sfx)
{
    int r = rand() % 100 + 1;
    int mult = get_multiplicator_stat(LUCK, game);

    if (r < 5 * mult - 10)
        return spawn_money(game, pos, "ruby_coin", sfx);
    if (r < 10 * mult - 10)
        return spawn_money(game, pos, "gold_coin", sfx);
    if (r < 25 * mult)
        return spawn_money(game, pos, "silver_coin", sfx);
    if (r < 75 * mult)
        return spawn_money(game, pos, "copper_coin", sfx);
    return;
}

static sfVector2f get_money_pos(sfVector2f pos, int radius)
{
    int r = rand() % 360;
    float a = r * PI / 180;
    sfVector2f dir = v2f(cos(a), sin(a));

    return add_vectors(pos, mult_vector(dir, rand_int(0, radius)));
}

void spawn_random_money_radius(game_t *game, sfVector2f pos,
    int radius, int amount)
{
    if (radius < 0 || amount <= 0)
        return;
    for (int i = 0; i < amount; i++) {
        spawn_random_money(game, get_money_pos(pos, radius), sfFalse);
    }
}
