/*
** EPITECH PROJECT, 2024
** My_RPG
** File description:
** music_manager
*/

#include "game.h"
#include "system.h"
#include "SFML/Audio.h"
#include "player.h"
#include "map.h"

static void change_music(game_t *game, char *path)
{
    if (game->system->music_manager != NULL)
        sfMusic_destroy(game->system->music_manager);
    game->system->music_manager = sfMusic_createFromFile(path);
    sfMusic_setVolume(game->system->music_manager, game->info->music_vol);
    sfMusic_setLoop(game->system->music_manager, sfTrue);
    sfMusic_play(game->system->music_manager);
}

void handle_music_boss(game_t *game)
{
    system_t *system = game->system;

    if (system->biome == BIOME1) {
        change_music(game, "res/music/anger.ogg");
    }
    if (system->biome == BIOME2) {
        change_music(game, "res/music/anxiety.ogg");
    }
    if (system->biome == BIOME3) {
        change_music(game, "res/music/despair.ogg");
    }
    if (system->biome == BIOME4) {
        change_music(game, "res/music/uber_boss.ogg");
    }
}

void handle_music_room(game_t *game)
{
    system_t *system = game->system;

    if (system->last_statut != COMBAT_BOSS && system->last_statut != START)
        return;
    if (system->biome == BIOME1)
        change_music(game, "res/music/floor1.ogg");
    if (system->biome == BIOME2)
        change_music(game, "res/music/floor2.ogg");
    if (system->biome == BIOME3)
        change_music(game, "res/music/floor3.ogg");
    if (system->biome == BIOME4)
        change_music(game, "res/music/floor3.ogg");
}

void handle_music_manager(game_t *game)
{
    if (game->system->last_statut != game->system->statut) {
        switch (game->system->statut) {
            case COMBAT_BOSS:
                handle_music_boss(game);
                break;
            case START:
                change_music(game, "res/music/spawn.ogg");
                break;
            default:
                handle_music_room(game);
                break;
        }
        game->system->last_statut = game->system->statut;
    }
    sfMusic_setVolume(game->system->music_manager, game->info->music_vol);
}

void end_game(game_t *game)
{
    game->player->hp = 0;
    player_take_dmg(game, 10);
    game->system->biome = HUB;
    set_tileset_system(game);
    set_map(game, "res/map/spawn/first_map.lua");
}
