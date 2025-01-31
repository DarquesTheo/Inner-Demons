/*
** EPITECH PROJECT, 2024
** handle_enemies.c
** File description:
** handle enemies functions
*/

#include "game.h"
#include "enemies.h"
#include "res.h"
#include "map.h"
#include "hitbox.h"
#include "system.h"

void draw_boss1_cast(game_t *game, boss1_t *node)
{
    for (int i = 0; i < NBR_CAST && node->rect.left > 0 &&
            node->rect.left < (int)
            sfTexture_getSize(game->res->mob->texture_cast_boss1).x; i++)
        sfRenderWindow_drawSprite(game->window, node->sprite[i], NULL);
}

void draw_spawn_enemies(game_t *game)
{
    for (mob_t *mob = game->map->mobs; mob != NULL; mob = mob->next)
        sfRenderWindow_drawSprite(game->window, mob->sprite_spawn, NULL);
}

void draw_enemies(game_t *game)
{
    for (mob_t *mob = game->map->mobs; mob != NULL; mob = mob->next) {
        sfRenderWindow_drawSprite(game->window, mob->sprite, NULL);
        place_sprite_hitbox(mob->hitbox, mob->sprite);
        if (game->info->debug)
            sfRenderWindow_drawRectangleShape(game->window,
                mob->hitbox->rect, NULL);
        if (mob->type == BOSS1)
            draw_boss1_cast(game, mob->boss_struct);
    }
}

static sfTexture *select_texture(mob_t *mob, game_t *game)
{
    if (mob->statut == MOVING)
        return game->res->mob->textures_move[mob->type];
    if (mob->statut == DYING)
        return game->res->mob->textures_die[mob->type];
    if (mob->statut == ATTACKING)
        return game->res->mob->textures_attack[mob->type];
    if (mob->statut == ATTACKING2 && mob->type == BOSS1)
        return game->res->mob->texture_attack2_boss1;
    if (mob->statut == ATTACKING2 && mob->type == BOSS2)
        return game->res->mob->texture_attack2_boss2;
    return game->res->mob->textures_move[mob->type];
}

static void test_mob_frame_attack2(mob_t *mob, game_t *game)
{
    boss3_t *boss3 = mob->boss_struct;

    if (mob->i_anim == mob->projectile->anim_cast &&
        mob->statut == ATTACKING) {
        enemy_shoot(game, mob);
    }
    if (mob->type == BOSS2 && mob->i_anim == 8 && mob->statut == ATTACKING2) {
        for (int i = 0; i < NBR_INVOC; i++)
            spawn_enemy_rand(game, game->system->multi_mob);
    }
    if (mob->i_anim == 14 && mob->type == BOSS3 && mob->statut == DYING)
        enemy_shoot(game, mob);
    if (mob->type == BOSS3 && mob->statut != DYING) {
        if (boss3->angle >= 360)
            boss3->angle = 0;
        else
            boss3->angle += 10;
        boss3_projectile_spell(mob, game, boss3->angle);
    }
}

static void test_mob_frame_attack(mob_t *mob, game_t *game)
{
    boss1_t *boss1 = mob->boss_struct;

    if (mob->type == BOSS1) {
        for (int i = 0; i < NBR_CAST && boss1->rect.left > 0 &&
            boss1->rect.left < (int)
            sfTexture_getSize(game->res->mob->texture_cast_boss1).x; i++) {
            sfSprite_setPosition(boss1->sprite[i], boss1->pos[i]);
            sfSprite_setTextureRect(boss1->sprite[i], boss1->rect);
        }
        for (int i = 0; i < NBR_CAST && boss1->rect.left == 4747; i++)
            boss1_projectile_spell(boss1->pos[i], mob, game);
        if (boss1->rect.left >
            (int) sfTexture_getSize(game->res->mob->texture_cast_boss1).x)
            boss1->rect.left = 0;
        if (boss1->rect.left != 0)
            boss1->rect.left += boss1->rect.width;
    }
    test_mob_frame_attack2(mob, game);
}

static void change_anim_spawn(mob_t *mob)
{
    if (mob->rect_spawn.left > 704)
        return;
    mob->rect_spawn.left += 64;
    sfSprite_setTextureRect(mob->sprite_spawn, mob->rect_spawn);
}

static void change_animation(mob_t *mob, game_t *game)
{
    sfIntRect rect = mob->rect;
    sfTexture *texture = select_texture(mob, game);

    sfSprite_setPosition(mob->sprite, mob->pos);
    if (sfTime_asSeconds(sfClock_getElapsedTime(mob->clock_anim)) > 0.1) {
        change_anim_spawn(mob);
        sfSprite_setTexture(mob->sprite, texture, sfFalse);
        test_mob_frame_attack(mob, game);
        rect.left = mob->i_anim * mob->img_width;
        mob->i_anim += 1;
        if (rect.left >= (int) sfTexture_getSize(texture).x) {
            rect.left = 0;
            mob->i_anim = 0;
            mob->attack_loop = 0;
        }
        sfSprite_setTextureRect(mob->sprite, rect);
        sfClock_restart(mob->clock_anim);
    }
}

static void handle_enemies2(game_t *game, int *slowed, mob_t *mob)
{
    if (mob->statut == ATTACKING || mob->statut == ATTACKING2) {
        *slowed = 1;
        mob->stats->speed = mob->stats->speed / 2;
    }
    if (mob->statut != DYING) {
        test_mob_attacking(mob, game);
        move_mob(mob, game);
    }
}

void handle_enemies(game_t *game)
{
    int slowed;

    for (mob_t *mob = game->map->mobs; mob != NULL;) {
        if (mob->i_anim == 0 && mob->statut == DYING &&
            mob->attack_loop == 0) {
            free_mob(&mob, &(game->map->mobs));
            continue;
        }
        slowed = 0;
        handle_enemies2(game, &slowed, mob);
        change_animation(mob, game);
        if (slowed == 1)
            mob->stats->speed = mob->stats->speed * 2;
        mob = mob->next;
    }
}
