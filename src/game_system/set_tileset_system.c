/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** set_tileset_system
*/

#include "game.h"
#include "system.h"
#include "res.h"

void set_tileset_system(game_t *game)
{
    if (game->system->biome == BIOME1)
        game->info->current_tileset = game->res->tilesets->floor1;
    if (game->system->biome == BIOME2)
        game->info->current_tileset = game->res->tilesets->floor2;
    if (game->system->biome == BIOME3)
        game->info->current_tileset = game->res->tilesets->floor3;
    if (game->system->biome == BIOME4)
        game->info->current_tileset = game->res->tilesets->floor4;
    if (game->system->biome == HUB)
        game->info->current_tileset = game->res->tilesets->spawn;
}
