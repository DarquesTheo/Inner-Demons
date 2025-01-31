/*
** EPITECH PROJECT, 2024
** attack.c
** File description:
** attack functions
*/

#include "enemies.h"
#include "const.h"
#include <math.h>
#include "anim.h"
#include "vector.h"
#include "utils.h"
#include "player.h"
#include "map.h"
#include <stdlib.h>

static int on_mob_projectile_col2(game_t *game, anim_t *ani,
    UNUSED mob_t *mob)
{
    anim_t *anim = get_default_anim();
    sfVector2f pos = sfSprite_getPosition(ani->sprite);

    anim->fps = 40;
    anim->img_width = 1280;
    anim->loop = sfFalse;
    sfSprite_setTexture(anim->sprite, get_tex(game, "mob_col"), 0);
    sfSprite_setOrigin(anim->sprite, (sfVector2f){32, 32});
    sfSprite_setPosition(anim->sprite, pos);
    sfSprite_setScale(anim->sprite, (sfVector2f){1.5, 1.5});
    anim->rect = init_intrect(64, 64);
    sfSprite_setTextureRect(anim->sprite, anim->rect);
    sfSprite_setRotation(anim->sprite, rand() % 360);
    add_anim(game, anim);
    return 1;
}

int on_mob_projectile_col(UNUSED game_t *game,
    UNUSED anim_t *ani, UNUSED mob_t *mob, col_type_t type)
{
    if (game->player->state == DASHING)
        return 0;
    if (type == COL_PLAYER)
        player_take_dmg(game, 1);
    if (type == COL_WALL || type == COL_PLAYER) {
        on_mob_projectile_col2(game, ani, mob);
    }
    return 1;
}

static void enemy_shoot3(game_t *game, anim_t *anim, float angle)
{
    sfSprite_setRotation(anim->sprite, angle);
    anim->hitbox = create_rect_hitbox(v2f(30, 30), v2f(0, 0));
    sfRectangleShape_setRotation(anim->hitbox->rect, angle);
    place_sprite_hitbox(anim->hitbox, anim->sprite);
    sfSprite_setScale(anim->sprite, (sfVector2f){4, 4});
    add_anim(game, anim);
}

static void enemy_shoot2(game_t *game, sfVector2f pos,
    sfVector2f move, float angle)
{
    anim_t *anim = get_default_anim();
    sfVector2f player_pos = sfSprite_getPosition(game->player->sprite);

    angle = -(atan2(pos.x - player_pos.x, pos.y - player_pos.y)
        * 180 / PI) - 90 + angle;
    anim->fps = 10;
    anim->img_width = 64;
    anim->duration = 10;
    anim->loop = sfTrue;
    anim->col->player = sfTrue;
    anim->col->map = sfTrue;
    anim->on_collide = &on_mob_projectile_col;
    sfSprite_setTexture(anim->sprite, game->res->projectile_mob->
        textures_attack_mob[rand() % NBR_PROJECTILE_COLOR], 0);
    sfSprite_setOrigin(anim->sprite, (sfVector2f){8, 7});
    sfSprite_setPosition(anim->sprite, pos);
    anim->rect = init_intrect(16, 14);
    sfSprite_setTextureRect(anim->sprite, anim->rect);
    anim->move = move;
    enemy_shoot3(game, anim, angle);
}

void enemy_shoot(game_t *game, mob_t *mob)
{
    sfVector2f player_pos = sfSprite_getPosition(game->player->sprite);
    float speed = mob->projectile->speed;
    sfVector2f dep = mult_vector(normalize_vector
        (get_vector_difference(mob->pos, player_pos)), speed);
    sfVector2f dep_tmp;
    sfVector2f bullet_start = add_vectors(mob->pos,
        get_bullet_start(mob->sprite, mob->projectile->distance, 0));
    float angle = rand() % (mob->projectile->angle_max * 2) -
        mob->projectile->angle_max;
    float rad;

    angle += -((mob->projectile->nbr - 1)) / 2 *
        mob->projectile->angle_between_each;
    for (int i = 0; i < mob->projectile->nbr; i++) {
        rad = angle * PI / 180;
        dep_tmp.x = dep.x * cos(rad) - dep.y * sin(rad);
        dep_tmp.y = dep.x * sin(rad) + dep.y * cos(rad);
        enemy_shoot2(game, bullet_start, dep_tmp, angle);
        angle += mob->projectile->angle_between_each;
    }
}

static void set_boss1_attack(boss1_t *node, mob_t *mob, game_t *game)
{
    mob->statut = ATTACKING2;
    node->rect.left = 1;
    for (int i = 0; i < NBR_CAST; i++) {
        node->pos[i] = get_rand_tile(game);
        node->pos[i].y -= 225;
        sfSprite_setPosition(node->sprite[i], node->pos[i]);
        sfSprite_setTextureRect(node->sprite[i], node->rect);
    }
}

void test_mob_attacking(mob_t *mob, game_t *game)
{
    if (mob->i_anim == 0 && (mob->statut == ATTACKING ||
        mob->statut == ATTACKING2) && mob->attack_loop == 0) {
        mob->statut = MOVING;
        mob->i_anim = 0;
    }
    if (10 < mob->pattern->luck_shooting) {
        mob->statut = ATTACKING;
        if (mob->type == BOSS1 && rand() % 2 == 0)
            set_boss1_attack(mob->boss_struct, mob, game);
        if (mob->type == BOSS2 && rand() % 4 == 0 &&
            get_nbr_enemies(game) < 10)
            mob->statut = ATTACKING2;
        mob->i_anim = 0;
        mob->pattern->luck_shooting = 0;
        mob->attack_loop = 1;
    }
}

void boss1_projectile_spell(sfVector2f pos, mob_t *mob, game_t *game)
{
    sfVector2f player_pos = sfSprite_getPosition(game->player->sprite);
    float speed = 500;
    sfVector2f dep = mult_vector(normalize_vector(get_vector_difference(
        add_vectors(pos, (sfVector2f) {-30, 225}), player_pos)), speed);
    sfVector2f dep_tmp;
    sfVector2f bullet_start = add_vectors(pos, (sfVector2f) {-30, 225});
    float angle = rand() % 90 - 45;
    float rad;

    angle += -(7 / 2) * 45;
    for (int i = 0; i < mob->projectile->nbr; i++) {
        rad = angle * PI / 180;
        dep_tmp.x = dep.x * cos(rad) - dep.y * sin(rad);
        dep_tmp.y = dep.x * sin(rad) + dep.y * cos(rad);
        enemy_shoot2(game, bullet_start, dep_tmp, angle);
        angle += 45;
    }
}

static void enemy_shoot4(game_t *game, sfVector2f pos,
    sfVector2f move, float angle)
{
    anim_t *anim = get_default_anim();

    anim->fps = 10;
    anim->img_width = 64;
    anim->duration = 10;
    anim->loop = sfTrue;
    anim->col->player = sfTrue;
    anim->col->map = sfTrue;
    anim->on_collide = &on_mob_projectile_col;
    sfSprite_setTexture(anim->sprite, game->res->projectile_mob->
        textures_attack_mob[rand() % NBR_PROJECTILE_COLOR], 0);
    sfSprite_setOrigin(anim->sprite, (sfVector2f){8, 7});
    sfSprite_setPosition(anim->sprite, pos);
    anim->rect = init_intrect(16, 14);
    sfSprite_setTextureRect(anim->sprite, anim->rect);
    anim->move = move;
    enemy_shoot3(game, anim, angle);
}

void boss3_projectile_spell(mob_t *mob, game_t *game, float angle)
{
    float speed = 1200;
    sfVector2f dep = mult_vector((sfVector2f) {1, 0}, speed);
    sfVector2f dep_tmp;
    sfVector2f bullet_start = mob->pos;
    float rad;

    rad = angle * PI / 180;
    dep_tmp.x = dep.x * cos(rad) - dep.y * sin(rad);
    dep_tmp.y = dep.x * sin(rad) + dep.y * cos(rad);
    enemy_shoot4(game, bullet_start, dep_tmp, angle);
}
