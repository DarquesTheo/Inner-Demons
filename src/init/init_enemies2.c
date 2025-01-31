/*
** EPITECH PROJECT, 2024
** init_enemies2.c
** File description:
** init enemies
*/

#include "enemies.h"
#include "res.h"
#include "hitbox.h"
#include "utils.h"
#include "map.h"
#include "anim.h"
#include "map.h"
#include <stdlib.h>

void *init_boss_struct(mob_type_t type, game_t *game)
{
    boss1_t *new1 = NULL;
    boss3_t *new2;

    if (type == BOSS3) {
        new2 = malloc(sizeof(boss3_t));
        new2->angle = 0;
        return new2;
    }
    if (type == BOSS1) {
        new1 = malloc(sizeof(boss1_t));
        for (int i = 0; i < NBR_CAST; i++) {
            new1->sprite[i] = sfSprite_create();
            sfSprite_setOrigin(new1->sprite[i], (sfVector2f) {339, 225});
            sfSprite_setTexture(new1->sprite[i],
                game->res->mob->texture_cast_boss1, sfFalse);
            new1->rect = (sfIntRect) {0, 0, 678, 450};
            sfSprite_setTextureRect(new1->sprite[i], new1->rect);
        }
    }
    return new1;
}

res_mob_t *init_mobs_struct4(res_mob_t *new)
{
    new->texture_cast_boss1 =
        sfTexture_createFromFile("res/enemies/Boss1/Spell.png", NULL);
    new->texture_attack2_boss1 =
        sfTexture_createFromFile("res/enemies/Boss1/Attack2.png", NULL);
    new->texture_attack2_boss2 =
        sfTexture_createFromFile("res/enemies/Boss2/Attack2.png", NULL);
    new->texture_spawn =
        sfTexture_createFromFile("res/enemies/Spawn.png", NULL);
    return new;
}

static hitbox_rect_t *init_mob_hitbox3(mob_t *new)
{
    hitbox_rect_t *hitbox;

    switch (new->type) {
        case CHEST:
            hitbox = create_rect_hitbox(v2f(80, 80), v2f(0, 0));
            break;
        default:
            hitbox = create_rect_hitbox(v2f(150, 100), v2f(0, 0));
    }
    return hitbox;
}

hitbox_rect_t *init_mob_hitbox2(mob_t *new)
{
    hitbox_rect_t *hitbox;

    switch (new->type) {
        case SKELETON:
            hitbox = create_rect_hitbox(v2f(60, 100), v2f(0, 10));
            break;
        case BOSS2:
            hitbox = create_rect_hitbox(v2f(80, 150), v2f(0, 0));
            break;
        case BOSS3:
            hitbox = create_rect_hitbox(v2f(150, 100), v2f(0, 0));
            break;
        case XENO:
            hitbox = create_rect_hitbox(v2f(80, 80), v2f(0, 0));
            break;
        default:
            hitbox = init_mob_hitbox3(new);
    }
    return hitbox;
}

static void init_mob_size_rect3(mob_t *new)
{
    switch (new->type) {
        case XENO:
            new->rect = (sfIntRect) {0, 0, 320, 320};
            new->img_width = 320;
            sfSprite_setOrigin(new->sprite, (sfVector2f) {130, 270});
            break;
        case CHEST:
            new->rect = (sfIntRect) {0, 0, 324, 324};
            new->img_width = 324;
            sfSprite_setOrigin(new->sprite, (sfVector2f) {162, 170});
            break;
        default:
            new->rect = (sfIntRect) {0, 0, 450, 450};
            new->img_width = 450;
            sfSprite_setOrigin(new->sprite, (sfVector2f) {225, 225});
    }
}

static void init_mob_size_rect2(mob_t *new)
{
    switch (new->type) {
        case BOSS2:
            new->rect = (sfIntRect) {0, 0, 640, 512};
            new->img_width = 640;
            sfSprite_setOrigin(new->sprite, (sfVector2f) {325, 375});
            break;
        case BOSS3:
            new->rect = (sfIntRect) {0, 0, 400, 400};
            new->img_width = 400;
            sfSprite_setOrigin(new->sprite, (sfVector2f) {200, 250});
            break;
        default:
            init_mob_size_rect3(new);
    }
}

void init_mob_size_rect(mob_t *new)
{
    switch (new->type) {
        case GOBLIN:
        case MUSHROOM:
        case EYE_FLY:
        case SKELETON:
            new->rect = (sfIntRect) {0, 0, 450, 450};
            new->img_width = 450;
            sfSprite_setOrigin(new->sprite, (sfVector2f) {225, 225});
            break;
        case BOSS1:
            new->rect = (sfIntRect) {0, 0, 678, 450};
            new->img_width = 678;
            sfSprite_setOrigin(new->sprite, (sfVector2f) {160, 300});
            break;
        default:
            init_mob_size_rect2(new);
    }
}

void spawn_enemy_rand(game_t *game, float mult)
{
    sfVector2f pos;
    sfRectangleShape *hitbox = sfRectangleShape_create();
    sfVector2f *rect_point_list;
    int good = 1;

    sfRectangleShape_setSize(hitbox, (sfVector2f) {300, 300});
    sfRectangleShape_setOrigin(hitbox, (sfVector2f) {150, 150});
    while (good != 0) {
        pos = get_rand_tile(game);
        good = 0;
        sfRectangleShape_setPosition(hitbox, pos);
        rect_point_list = get_rectangle_points(5, hitbox);
        for (int i = 0; i < 20; i++) {
            good += get_tile_point_col(game, rect_point_list[i]);
        }
        free(rect_point_list);
    }
    sfRectangleShape_destroy(hitbox);
    spawn_enemy(rand() % 6, pos, game, mult);
}
