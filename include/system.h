/*
** EPITECH PROJECT, 2024
** system.h
** File description:
** system.h
*/

#ifndef SYSTEM_H_
    #define SYSTEM_H_

    #define NBR_BIOME 1

    #include "SFML/System/Clock.h"
    #include "SFML/Audio.h"

typedef struct game_s game_t;

typedef enum biome_s {
    BIOME1,
    BIOME2,
    BIOME3,
    BIOME4,
    HUB
} biome_t;

typedef enum game_statut_s {
    SHOPING,
    COMBAT_BOSS,
    COMBAT,
    WAITING,
    ENDING,
    START
} game_statut_t;

typedef struct system_s {
    int biome_sum[4];
    float multi_mob;
    sfClock *clock;
    enum game_statut_s statut;
    enum game_statut_s last_statut;
    int wave;
    int room;
    int floor;
    enum biome_s biome;
    char *map_boss[4];
    char *map_mar[3];
    int min_mobs;
    int max_mobs;
    sfMusic *music_manager;
    sfBool portal_open;
    sfClock *game_time;
} system_t;

void init_system(game_t *game);
void handle_system(game_t *game);
void change_system_map(game_t *game);
void change_biome(game_t *game);
void set_tileset_system(game_t *game);
void handle_music_manager(game_t *game);
void start_game_system(game_t *game);
void end_game(game_t *game);
void start_first_map(game_t *game);
void set_tileset_system(game_t *game);

#endif
