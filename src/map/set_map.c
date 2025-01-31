/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** set_map
*/

#include "game.h"
#include "map.h"
#include "res.h"
#include "system.h"
#include "player.h"

//set path at NULL for random map
void set_map(game_t *game, char *path)
{
    if (path == NULL)
        game->map = get_map_from_lua(get_random_map_file(game), game);
    else
        game->map = get_map_from_lua(path, game);
    if (game->system->biome == BIOME1)
        set_room_collisions(game->map, "res/map/floor1/collision.txt");
    if (game->system->biome == BIOME2)
        set_room_collisions(game->map, "res/map/floor2/collision.txt");
    if (game->system->biome == BIOME3)
        set_room_collisions(game->map, "res/map/floor3/collision.txt");
    if (game->system->biome == BIOME4)
        set_room_collisions(game->map, "res/map/floor3/collision.txt");
    if (game->system->biome == HUB)
        set_room_collisions(game->map, "res/map/spawn/collision.txt");
    game->map->layer1 = load_tilemap(game->info->current_tileset,
    (sfVector2i){16, 16}, game->map->int_layer1, game->map->size);
    game->map->layer2 = load_tilemap(game->info->current_tileset,
    (sfVector2i){16, 16}, game->map->int_layer2, game->map->size);
    game->map->mobs = NULL;
    sfSprite_setPosition(game->player->sprite, game->map->player);
}
