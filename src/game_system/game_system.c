/*
** EPITECH PROJECT, 2024
** game_system.c
** File description:
** game system functions
*/

#include "system.h"
#include <stdlib.h>
#include "enemies.h"
#include "map.h"
#include "utils.h"
#include "objects.h"
#include "artefact.h"
#include "ui.h"
#include "player.h"
#include "dialogue.h"

static void change_biome2(game_t *game)
{
    system_t *system = game->system;

    if (system->biome_sum[2] == -1) {
        system->biome = 3 - system->biome_sum[0] - system->biome_sum[1];
        system->biome_sum[2] = system->biome;
        return;
    }
    if (system->biome_sum[3] == -1) {
        system->biome = 3;
        system->biome_sum[3] = system->biome;
    }
}

void change_biome(game_t *game)
{
    system_t *system = game->system;

    if (system->biome_sum[0] == -1) {
        system->biome = rand() % 3;
        system->biome_sum[0] = system->biome;
        return;
    }
    if (system->biome_sum[1] == -1) {
        system->biome = rand() % 2;
        if ((int) system->biome == system->biome_sum[0])
            system->biome += 1;
        system->biome_sum[1] = system->biome;
        return;
    }
    change_biome2(game);
}

static void spawn_enemies_system(game_t *game)
{
    system_t *system = game->system;
    int random = rand() % (system->max_mobs - system->min_mobs + 1);

    random += system->min_mobs;
    for (int i = 0; i < random; i++) {
        spawn_enemy_rand(game, system->multi_mob);
    }
    system->statut = COMBAT;
}

static void spawn_boss_system(game_t *game)
{
    system_t *system = game->system;

    if (system->biome == BIOME1) {
        spawn_enemy(BOSS3, (sfVector2f) {1000, 1000}, game, system->multi_mob);
    }
    if (system->biome == BIOME2) {
        spawn_enemy(BOSS2, (sfVector2f) {1000, 1000}, game, system->multi_mob);
    }
    if (system->biome == BIOME3) {
        spawn_enemy(BOSS1, (sfVector2f) {1000, 1000}, game, system->multi_mob);
    }
    if (system->biome == BIOME4) {
        spawn_enemy(BOSS1, (sfVector2f) {1000, 1000}, game, system->multi_mob);
        spawn_enemy(BOSS2, (sfVector2f) {1500, 1000}, game, system->multi_mob);
        spawn_enemy(BOSS3, (sfVector2f) {2000, 1000}, game, system->multi_mob);
    }
    system->statut = COMBAT_BOSS;
}

static void change_system_map3(system_t *system, game_t *game)
{
    if (system->statut == START) {
        start_game_system(game);
    }
}

static void handle_system3(system_t *system, game_t *game)
{
    if (system->statut == START) {
        if (game->player->wp1 && game->player->wp2 && !system->portal_open) {
            spawn_portal(game, game->map->portal);
            system->portal_open = sfTrue;
        }
    }
}

static void handle_system2(system_t *system, game_t *game)
{
    if (system->statut == WAITING &&
        sfTime_asSeconds(sfClock_getElapsedTime(system->clock)) > 3 &&
        game->dialogue == NULL) {
        if (system->room < 5 && system->floor < 4)
            spawn_enemies_system(game);
        else
            spawn_boss_system(game);
    }
    if (system->statut == COMBAT_BOSS) {
        if (game->map->mobs == NULL) {
            spawn_portal(game, game->map->portal);
            add_boss_stat_line(game, DODGE + system->biome);
            system->statut = ENDING;
            game->system->multi_mob += 0.5;
            system->room += 1;
            system->wave = 0;
        }
    }
    handle_system3(system, game);
}

void handle_system(game_t *game)
{
    system_t *system = game->system;

    if (system->statut == COMBAT) {
        if (game->map->mobs == NULL && system->wave < 3) {
            system->statut = WAITING;
            sfClock_restart(system->clock);
            system->wave += 1;
        }
        if (game->map->mobs == NULL && system->wave >= 3) {
            spawn_portal(game, game->map->portal);
            system->statut = ENDING;
            system->wave = 0;
            system->room += 1;
        }
    }
    handle_system2(system, game);
    handle_music_manager(game);
}

static void change_system_map2(game_t *game)
{
    if (game->system->statut == ENDING) {
        if (game->system->floor >= 4)
            return end_game(game);
        set_map(game, game->system->map_mar[game->system->biome]);
        game->system->multi_mob += 0.2;
        game->system->min_mobs += 1 * game->system->floor;
        game->system->max_mobs += 1 * game->system->floor;
        if (game->system->room < 5 && game->system->room > 1)
            add_normal_stat_line(game);
        if (game->system->room >= 6) {
            game->system->floor += 1;
            game->system->room = 1;
            change_biome(game);
        }
        spawn_portal(game, game->map->portal);
        game->system->statut = SHOPING;
    }
    change_system_map3(game->system, game);
}

void change_system_map(game_t *game)
{
    if (game->system->statut == SHOPING) {
        set_tileset_system(game);
        if (game->system->floor == 4) {
            set_map(game, "res/map/boss/uber_map.lua");
            game->system->statut = WAITING;
            return;
        }
        if (game->system->room < 5)
            set_map(game, NULL);
        else {
            set_map(game, game->system->map_boss[game->system->biome]);
            dial_boss(game, game->system->biome + 1);
        }
        game->system->statut = WAITING;
    }
    change_system_map2(game);
}
