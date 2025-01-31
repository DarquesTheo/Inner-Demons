/*
** EPITECH PROJECT, 2024
** init_system.c
** File description:
** init_system
*/

#include "system.h"
#include "game.h"
#include "map.h"
#include "res.h"
#include "artefact.h"
#include <stdlib.h>
#include <string.h>
#include "dialogue.h"

void init_biome_sum(game_t *game, system_t *new)
{
    for (int i = 0; i < 4; i++)
        new->biome_sum[i] = -1;
    new->map_mar[0] = strdup("res/map/merchant/map_mar1.lua");
    new->map_mar[1] = strdup("res/map/merchant/map_mar2.lua");
    new->map_mar[2] = strdup("res/map/merchant/map_mar3.lua");
    new->music_manager = NULL;
    new->portal_open = sfFalse;
    new->game_time = sfClock_create();
    add_dialogue(game, "hub_5.txt");
    add_dialogue(game, "hub_4.txt");
    add_dialogue(game, "hub_3.txt");
    add_dialogue(game, "hub_2.txt");
    add_dialogue(game, "hub_1.txt");
}

void init_system(game_t *game)
{
    system_t *new = malloc(sizeof(system_t));

    new->map_boss[0] = strdup("res/map/boss/boss1.lua");
    new->map_boss[1] = strdup("res/map/boss/boss2.lua");
    new->map_boss[2] = strdup("res/map/boss/boss3.lua");
    new->map_boss[3] = strdup("res/map/boss/uber_map.lua");
    new->clock = sfClock_create();
    new->statut = START;
    new->last_statut = ENDING;
    new->multi_mob = 1;
    new->wave = 0;
    new->room = 1;
    new->floor = 1;
    init_biome_sum(game, new);
    new->min_mobs = 2;
    new->max_mobs = 3;
    new->biome = HUB;
    game->system = new;
    set_tileset_system(game);
    set_map(game, "res/map/spawn/first_map.lua");
}

void start_game_system(game_t *game)
{
    game->system->statut = WAITING;
    set_map(game, NULL);
    sfClock_restart(game->system->clock);
}

void start_first_map(game_t *game)
{
    add_dialogue(game, "start_8.txt");
    add_dialogue(game, "start_7.txt");
    add_dialogue(game, "start_6.txt");
    add_dialogue(game, "start_5.txt");
    add_dialogue(game, "start_4.txt");
    add_dialogue(game, "start_3.txt");
    add_dialogue(game, "start_2.txt");
    add_dialogue(game, "start_1.txt");
    add_boss_stat_line(game, COUP_CRITIQUE);
    change_biome(game);
    set_tileset_system(game);
    if (game->system->biome == BIOME1)
        set_map(game, "res/map/start/start_floor1.lua");
    if (game->system->biome == BIOME2)
        set_map(game, "res/map/start/start_floor2.lua");
    if (game->system->biome == BIOME3)
        set_map(game, "res/map/start/start_floor3.lua");
}
