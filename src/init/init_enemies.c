/*
** EPITECH PROJECT, 2024
** init_enemies.c
** File description:
** init enemies
*/

#include "game.h"
#include "enemies.h"
#include "res.h"
#include "hitbox.h"
#include "utils.h"
#include "map.h"
#include "anim.h"
#include "map.h"
#include <stdlib.h>

res_projectile_mob_t *init_projectile_mob_struct(void)
{
    res_projectile_mob_t *new = malloc(sizeof(res_projectile_mob_t));
    char str[44] = "res/enemies/projectile/projectile_mob/1.png";

    for (int i = 0; i < NBR_PROJECTILE_COLOR; i++) {
        str[38] = i + 48 + 1;
        new->textures_attack_mob[i] = sfTexture_createFromFile(str, NULL);
    }
    return new;
}

static res_mob_t *init_mobs_struct3(res_mob_t *new)
{
    sfTexture *move[I_MAX_ENEMIES] = {
        sfTexture_createFromFile("res/enemies/Mushroom/Run.png", NULL),
        sfTexture_createFromFile("res/enemies/Eye_fly/Flight.png", NULL),
        sfTexture_createFromFile("res/enemies/Goblin/Run.png", NULL),
        sfTexture_createFromFile("res/enemies/Skeleton/Walk.png", NULL),
        sfTexture_createFromFile("res/enemies/Chest/Run.png", NULL),
        sfTexture_createFromFile("res/enemies/Xeno/Run.png", NULL),
        sfTexture_createFromFile("res/enemies/Boss1/Walk.png", NULL),
        sfTexture_createFromFile("res/enemies/Boss2/Fly.png", NULL),
        sfTexture_createFromFile("res/enemies/Boss3/Run.png", NULL)};

    for (int i = 0; i < I_MAX_ENEMIES; i++)
        new->textures_move[i] = move[i];
    return init_mobs_struct4(new);
}

static res_mob_t *init_mobs_struct2(res_mob_t *new)
{
    sfTexture *die[I_MAX_ENEMIES] = {
        sfTexture_createFromFile("res/enemies/Mushroom/Death.png", NULL),
        sfTexture_createFromFile("res/enemies/Eye_fly/Death.png", NULL),
        sfTexture_createFromFile("res/enemies/Goblin/Death.png", NULL),
        sfTexture_createFromFile("res/enemies/Skeleton/Death.png", NULL),
        sfTexture_createFromFile("res/enemies/Chest/Death.png", NULL),
        sfTexture_createFromFile("res/enemies/Xeno/Death.png", NULL),
        sfTexture_createFromFile("res/enemies/Boss1/Death.png", NULL),
        sfTexture_createFromFile("res/enemies/Boss2/Death.png", NULL),
        sfTexture_createFromFile("res/enemies/Boss3/Death.png", NULL)};

    for (int i = 0; i < I_MAX_ENEMIES; i++)
        new->textures_die[i] = die[i];
    return init_mobs_struct3(new);
}

res_mob_t *init_mobs_struct(void)
{
    res_mob_t *new = malloc(sizeof(res_mob_t));
    sfTexture *attack[I_MAX_ENEMIES] = {
        sfTexture_createFromFile("res/enemies/Mushroom/Attack.png", NULL),
        sfTexture_createFromFile("res/enemies/Eye_fly/Attack.png", NULL),
        sfTexture_createFromFile("res/enemies/Goblin/Attack.png", NULL),
        sfTexture_createFromFile("res/enemies/Skeleton/Attack.png", NULL),
        sfTexture_createFromFile("res/enemies/Chest/Attack.png", NULL),
        sfTexture_createFromFile("res/enemies/Xeno/Attack.png", NULL),
        sfTexture_createFromFile("res/enemies/Boss1/Attack1.png", NULL),
        sfTexture_createFromFile("res/enemies/Boss2/Attack1.png", NULL),
        sfTexture_createFromFile("res/enemies/Boss3/Attack.png", NULL)};

    for (int i = 0; i < I_MAX_ENEMIES; i++)
        new->textures_attack[i] = attack[i];
    return init_mobs_struct2(new);
}

static stats_mob_t *init_stats_mob(mob_type_t type, float mult)
{
    stats_mob_t *stats = malloc(sizeof(stats_mob_t));

    stats->max_hp = stats_table[type].max_hp * mult;
    stats->cur_hp = stats_table[type].cur_hp * mult;
    stats->speed = stats_table[type].speed;
    stats->max_range = stats_table[type].max_range;
    stats->min_range = stats_table[type].min_range;
    stats->increase_luck = stats_table[type].increase_luck;
    return stats;
}

static projectile_t *init_projectile_mob(mob_type_t type)
{
    projectile_t *projectile = malloc(sizeof(projectile_t));

    projectile->anim_cast = projectile_table[type].anim_cast;
    projectile->distance = projectile_table[type].distance;
    projectile->speed = projectile_table[type].speed;
    projectile->angle_max = projectile_table[type].angle_max;
    projectile->nbr = projectile_table[type].nbr;
    projectile->angle_between_each = projectile_table[type].angle_between_each;
    return projectile;
}

void init_pattern_mob(mob_t *mob)
{
    pattern_t *new = malloc(sizeof(pattern_t));

    mob->pattern = new;
    new->clock_move = sfClock_create();
    new->clock_shot = sfClock_create();
    new->dir = (sfVector2f) {0, 0};
    new->in_pattern = 0;
    new->luck_shooting = 0;
    new->time = 0;
}

static hitbox_rect_t *init_mob_hitbox(mob_t *new)
{
    hitbox_rect_t *hitbox;

    switch (new->type) {
        case EYE_FLY:
            hitbox = create_rect_hitbox(v2f(100, 60), v2f(0, 10));
            break;
        case MUSHROOM:
            hitbox = create_rect_hitbox(v2f(60, 100), v2f(0, 20));
            break;
        case GOBLIN:
            hitbox = create_rect_hitbox(v2f(70, 100), v2f(0, 20));
            break;
        case BOSS1:
            hitbox = create_rect_hitbox(v2f(180, 250), v2f(0, 20));
            break;
        default:
            hitbox = init_mob_hitbox2(new);
    }
    return hitbox;
}

void spawn_enemy2(game_t *game, mob_t *new, sfVector2f pos)
{
    new->prev = NULL;
    new->next = game->map->mobs;
    if (game->map->mobs != NULL)
        game->map->mobs->prev = new;
    game->map->mobs = new;
    new->hitbox = init_mob_hitbox(new);
    new->sprite_spawn = sfSprite_create();
    sfSprite_setTexture(new->sprite_spawn, game->res->mob->texture_spawn, 0);
    new->rect_spawn = (sfIntRect) {0, 0, 64, 64};
    sfSprite_setTextureRect(new->sprite_spawn, new->rect_spawn);
    sfSprite_setPosition(new->sprite_spawn, pos);
    sfSprite_setOrigin(new->sprite_spawn, (sfVector2f) {32, 32});
    sfSprite_setScale(new->sprite_spawn, (sfVector2f) {3, 3});
    init_pattern_mob(new);
}

void spawn_enemy(mob_type_t type, sfVector2f pos, game_t *game, float mult)
{
    mob_t *new = malloc(sizeof(mob_t));

    new->type = type;
    new->stats = init_stats_mob(type, mult);
    new->projectile = init_projectile_mob(type);
    new->clock_anim = sfClock_create();
    new->clock_move = sfClock_create();
    new->pos = pos;
    new->attack_loop = 0;
    new->statut = MOVING;
    new->sprite = sfSprite_create();
    sfSprite_setTexture(new->sprite, game->res->mob->textures_move[type], 0);
    init_mob_size_rect(new);
    sfSprite_setTextureRect(new->sprite, new->rect);
    new->i_anim = 1;
    new->boss_struct = init_boss_struct(type, game);
    spawn_enemy2(game, new, pos);
}
