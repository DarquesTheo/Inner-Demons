/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** spawn_random_weapon
*/

#include "objects.h"
#include "utils.h"
#include "game.h"
#include "res.h"
#include <stdlib.h>
#include "player.h"
#include "artefact.h"

//angle at -1 for random
void spawn_random_weapon(game_t *game, sfVector2f pos, int angle)
{
    int r = rand() % WEAPON_NB;

    if (rand() % 100 * get_multiplicator_stat(LUCK, game) < 70 && angle == -1)
        return;
    if (r == 0)
        spawn_weapon(game, pos, create_ak47(game->res), angle);
    if (r == 1)
        spawn_weapon(game, pos, create_smg(game->res), angle);
    if (r == 2)
        spawn_weapon(game, pos, create_shotgun(game->res), angle);
    if (r == 3)
        spawn_weapon(game, pos, create_laser_gun(game->res), angle);
    if (r == 4)
        spawn_weapon(game, pos, create_canon(game), angle);
    if (r == 5)
        spawn_weapon(game, pos, create_wind_staff(game->res), angle);
}
