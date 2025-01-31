/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** ak47
*/

#include "player.h"
#include "res.h"
#include "const.h"
#include "anim.h"
#include "sound_manager.h"
#include <math.h>
#include <string.h>
#include "utils.h"
#include "vector.h"
#include <stdlib.h>
#include "artefact.h"

int on_shotgun_col(game_t *game, anim_t *ani, UNUSED mob_t *mob,
    col_type_t type)
{
    anim_t *anim = get_default_anim();
    sfVector2f pos = sfSprite_getPosition(ani->sprite);

    if (mob && type == COL_ENEMY)
        enemy_take_dmg(game, mob, ani->dmg);
    anim->fps = 20;
    anim->img_width = 448;
    anim->duration = -1;
    anim->loop = sfFalse;
    sfSprite_setTexture(anim->sprite,
    game->res->weapons->ak47_col, 0);
    sfSprite_setOrigin(anim->sprite, (sfVector2f){32, 32});
    sfSprite_setPosition(anim->sprite, pos);
    sfSprite_setScale(anim->sprite, (sfVector2f){1, 1});
    anim->rect = init_intrect(64, 64);
    sfSprite_setTextureRect(anim->sprite, anim->rect);
    anim->move = v2f(0.0f, 0.0f);
    sfSprite_setRotation(anim->sprite, rand() % 360);
    add_anim(game, anim);
    return 1;
}

static void shotgun_bullet2(game_t *game, anim_t *anim)
{
    anim->rect = init_intrect(8, 5);
    anim->rect.left = (rand() % 4) * 10;
    sfSprite_setTextureRect(anim->sprite, anim->rect);
    anim->hitbox = create_rect_hitbox(v2f(16, 16), v2f(0, 0));
    sfRectangleShape_setRotation(anim->hitbox->rect,
    sfSprite_getRotation(anim->sprite));
    place_sprite_hitbox(anim->hitbox, anim->sprite);
    anim->col->map = sfTrue;
    anim->col->ennemy = sfTrue;
    anim->col->object = sfTrue;
    add_anim(game, anim);
}

static void shotgun_bullet(game_t *game, sfVector2f muzzlepos,
    weapon_t *wp)
{
    anim_t *anim = get_default_anim();

    anim->type = ANIM_PPROJ;
    anim->speed = 2000;
    anim->dmg = wp->dmg * wp->lvl;
    set_bullet_dep(game, wp, anim);
    anim->fps = 20;
    anim->img_width = 32;
    anim->time_count = 0;
    anim->duration = 0.15;
    anim->loop = sfTrue;
    anim->on_collide = &on_shotgun_col;
    sfSprite_setTexture(anim->sprite,
    game->res->weapons->shotgun_bullet, 0);
    sfSprite_setOrigin(anim->sprite, (sfVector2f){3, 2});
    sfSprite_setPosition(anim->sprite, muzzlepos);
    sfSprite_setScale(anim->sprite, (sfVector2f){2, 2});
    shotgun_bullet2(game, anim);
}

void shotgun_shoot(game_t *game, weapon_t *wp)
{
    sfVector2f muzzlepos = get_muzzle_pos(wp->sprite, v2f(24, 2));

    play_sound(game, "shotgun_shoot", rand_float(0.5, 0.8));
    if ((rand() % 100) + 1 <=
    (get_multiplicator_stat(DOUBLE_SHOT, game) - 1) * 100) {
        muzzlepos.y += 25;
        for (int i = 0; i < 20; i++) {
            shotgun_bullet(game, get_bullet_spawn(wp->sprite, muzzlepos), wp);
        }
        muzzlepos.y -= 50;
    }
    for (int i = 0; i < 20; i++) {
        shotgun_bullet(game, get_bullet_spawn(wp->sprite, muzzlepos), wp);
    }
}

weapon_t *create_shotgun(res_t *res)
{
    weapon_t *weapon = malloc(sizeof(weapon_t));

    weapon->name = strdup("shotgun");
    weapon->shoot = &shotgun_shoot;
    weapon->dmg = 4;
    weapon->lvl = 1;
    weapon->sprite = sfSprite_create();
    weapon->angle_offset = 0;
    weapon->fire_rate = 0.75;
    weapon->spray = 30;
    weapon->clock = sfClock_create();
    weapon->texture = res->weapons->shotgun;
    sfSprite_setTexture(weapon->sprite, res->weapons->shotgun, 0);
    sfSprite_setScale(weapon->sprite, (sfVector2f){3, 3});
    sfSprite_setOrigin(weapon->sprite, (sfVector2f){4, 5});
    return weapon;
}
