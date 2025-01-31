/*
** EPITECH PROJECT, 2024
** enemies
** File description:
** enemies
*/

#ifndef ENEMIES_H
    #define ENEMIES_H
    #include <SFML/Graphics.h>
    #include "game.h"

    #define I_MAX_ENEMIES 9
    #define NBR_PROJECTILE_COLOR 6
    #define NBR_CAST 6
    #define NBR_INVOC 3

typedef struct hitbox_rect_s hitbox_rect_t;

typedef enum {
    MOVING,
    ATTACKING,
    DYING,
    ATTACKING2
} mob_statut_t;

typedef enum {
    MUSHROOM,
    EYE_FLY,
    GOBLIN,
    SKELETON,
    CHEST,
    XENO,
    BOSS1,
    BOSS2,
    BOSS3
} mob_type_t;

typedef struct res_mob_s {
    sfTexture *textures_attack[I_MAX_ENEMIES];
    sfTexture *textures_move[I_MAX_ENEMIES];
    sfTexture *textures_die[I_MAX_ENEMIES];
    sfTexture *texture_cast_boss1;
    sfTexture *texture_attack2_boss1;
    sfTexture *texture_attack2_boss2;
    sfTexture *texture_spawn;
} res_mob_t;

typedef struct res_projectile_mob_s {
    sfTexture *textures_attack_mob[NBR_PROJECTILE_COLOR];
} res_projectile_mob_t;

typedef struct projectile_s {
    int anim_cast;
    float distance;
    int speed;
    int angle_max;
    int nbr;
    int angle_between_each;
} projectile_t;

//projectile table
extern projectile_t projectile_table[I_MAX_ENEMIES];

typedef struct stats_mob_s {
    float max_hp;
    float cur_hp;
    int speed;
    int max_range;
    int min_range;
    float increase_luck;
} stats_mob_t;

//stats table
extern stats_mob_t stats_table[I_MAX_ENEMIES];

typedef struct pattern_s {
    sfClock *clock_move;
    sfClock *clock_shot;
    sfVector2f dir;
    int time;
    int in_pattern;
    float luck_shooting;
} pattern_t;

typedef struct boss3_s {
    float angle;
} boss3_t;

typedef struct boss1_s {
    sfIntRect rect;
    sfSprite *sprite[NBR_CAST];
    sfVector2f pos[NBR_CAST];
} boss1_t;

typedef struct mob_s {
    projectile_t *projectile;
    int i_anim;
    mob_statut_t statut;
    sfVector2f pos;
    mob_type_t type;
    sfIntRect rect_spawn;
    sfSprite *sprite_spawn;
    sfSprite *sprite;
    sfClock *clock_anim;
    sfClock *clock_move;
    struct pattern_s *pattern;
    sfIntRect rect;
    int img_width;
    struct mob_s *next;
    struct mob_s *prev;
    stats_mob_t *stats;
    hitbox_rect_t *hitbox;
    int attack_loop;
    void *boss_struct;
} mob_t;

void handle_enemies(game_t *game);
res_mob_t *init_mobs_struct(void);
void draw_enemies(game_t *game);
void spawn_enemy(mob_type_t type, sfVector2f pos, game_t *game, float mult);
void move_mob(mob_t *mob, game_t *game);
sfVector2f mob_random_move(mob_t *mob, game_t *game, sfVector2f move);
void change_shooting_luck(mob_t *mob, float full_distance);
void test_mob_attacking(mob_t *mob, game_t *game);
void free_mob(mob_t **mob, mob_t **list);
void enemy_take_dmg(game_t *game, mob_t *mob, float dmg);
void enemy_shoot(game_t *game, mob_t *mob);
res_projectile_mob_t *init_projectile_mob_struct(void);
void init_mob_size_rect(mob_t *new);
hitbox_rect_t *init_mob_hitbox2(mob_t *new);
res_mob_t *init_mobs_struct4(res_mob_t *new);
void *init_boss_struct(mob_type_t type, game_t *game);
void boss1_projectile_spell(sfVector2f pos, mob_t *mob, game_t *game);
int test_hitbox_col_mob(mob_t *mob, sfVector2f move, game_t *game);
void spawn_enemy_rand(game_t *game, float mult);
int get_nbr_enemies(game_t *game);
void boss3_projectile_spell(mob_t *mob, game_t *game, float angle);
void draw_spawn_enemies(game_t *game);
void free_mob_res(res_mob_t *res);
void free_all_mobs(game_t *game);

#endif
