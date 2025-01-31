/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** init_player_res
*/

#include "res.h"
#include <stdlib.h>
#include <stdio.h>

void init_player_res2(player_res_t *player_res)
{
    player_res->dash_up =
    sfTexture_createFromFile("res/player/dash_up.png", NULL);
    player_res->dash_down =
    sfTexture_createFromFile("res/player/dash_down.png", NULL);
    player_res->dash_left =
    sfTexture_createFromFile("res/player/dash_left.png", NULL);
    player_res->dash_right =
    sfTexture_createFromFile("res/player/dash_right.png", NULL);
}

player_res_t *init_player_res(void)
{
    player_res_t *player_res = malloc(sizeof(player_res_t));

    player_res->move_up =
    sfTexture_createFromFile("res/player/move_up.png", NULL);
    player_res->move_down =
    sfTexture_createFromFile("res/player/move_down.png", NULL);
    player_res->move_left =
    sfTexture_createFromFile("res/player/move_left.png", NULL);
    player_res->move_right =
    sfTexture_createFromFile("res/player/move_right.png", NULL);
    player_res->idle_up =
    sfTexture_createFromFile("res/player/idle_up.png", NULL);
    player_res->idle_down =
    sfTexture_createFromFile("res/player/idle_down.png", NULL);
    player_res->idle_left =
    sfTexture_createFromFile("res/player/idle_left.png", NULL);
    player_res->idle_right =
    sfTexture_createFromFile("res/player/idle_right.png", NULL);
    init_player_res2(player_res);
    return player_res;
}
