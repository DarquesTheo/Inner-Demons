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

static void on_laser_gun_col2(game_t *game, anim_t *ani, UNUSED mob_t *mob)
{
    anim_t *anim = get_default_anim();
    sfVector2f pos = sfSprite_getPosition(ani->sprite);

    anim->fps = 20;
    anim->img_width = 448;
    anim->duration = -1;
    anim->loop = sfFalse;
    sfSprite_setTexture(anim->sprite,
    game->res->weapons->ak47_col, 0);
    sfSprite_setColor(anim->sprite, (sfColor){255, 0, 0, 255});
    sfSprite_setOrigin(anim->sprite, (sfVector2f){32, 32});
    sfSprite_setPosition(anim->sprite, pos);
    sfSprite_setScale(anim->sprite, (sfVector2f){3, 3});
    anim->rect = init_intrect(64, 64);
    sfSprite_setTextureRect(anim->sprite, anim->rect);
    anim->move = v2f(0.0f, 0.0f);
    sfSprite_setRotation(anim->sprite, rand() % 360);
    add_anim(game, anim);
}

int on_laser_gun_col(game_t *game, anim_t *ani, UNUSED mob_t *mob,
    UNUSED col_type_t type)
{
    sfBool do_anim = sfFalse;

    if (!is_mob_in_hit_list(ani->col->hit_list, mob)) {
        enemy_take_dmg(game, mob, ani->dmg);
        add_mob_hit(&(ani->col->hit_list), mob);
        do_anim = sfTrue;
    }
    if ((!mob) || do_anim)
        on_laser_gun_col2(game, ani, mob);
    return 0;
}

static void laser_gun_bullet2(game_t *game, anim_t *anim)
{
    anim->rect = init_intrect(57, 91);
    sfSprite_setTextureRect(anim->sprite, anim->rect);
    anim->hitbox = create_rect_hitbox(v2f(30, 91), v2f(0, 0));
    sfRectangleShape_setRotation(anim->hitbox->rect,
    sfSprite_getRotation(anim->sprite));
    place_sprite_hitbox(anim->hitbox, anim->sprite);
    anim->col->map = sfTrue;
    anim->col->ennemy = sfTrue;
    anim->col->object = sfTrue;
    add_anim(game, anim);
}

static void laser_gun_bullet(game_t *game, sfVector2f muzzlepos,
    weapon_t *wp)
{
    anim_t *anim = get_default_anim();

    anim->type = ANIM_PPROJ;
    anim->dmg = wp->dmg * wp->lvl;
    anim->speed = 3000;
    set_bullet_dep(game, wp, anim);
    anim->fps = -1;
    anim->img_width = 91;
    anim->time_count = 0;
    anim->duration = 2;
    anim->loop = sfTrue;
    anim->on_collide = &on_laser_gun_col;
    anim->nb_hit = 30;
    sfSprite_setTexture(anim->sprite,
    game->res->weapons->laser_gun_bullet, 0);
    sfSprite_setOrigin(anim->sprite, (sfVector2f){57 / 2, 91 / 2});
    sfSprite_setPosition(anim->sprite, muzzlepos);
    sfSprite_setRotation(anim->sprite,
    sfSprite_getRotation(wp->sprite) + 90);
    laser_gun_bullet2(game, anim);
}

void laser_gun_shoot(game_t *game, weapon_t *wp)
{
    sfVector2f muzzlepos = get_muzzle_pos(wp->sprite, v2f(28, 4));

    play_sound(game, "laser_gun_shoot", rand_float(0.8, 1.2));
    if ((rand() % 100) + 1 <=
    (get_multiplicator_stat(DOUBLE_SHOT, game) - 1) * 100) {
        muzzlepos.y += 15;
        laser_gun_bullet(game, get_bullet_spawn(wp->sprite, muzzlepos), wp);
        muzzlepos.y -= 30;
    }
    laser_gun_bullet(game, get_bullet_spawn(wp->sprite, muzzlepos), wp);
}

weapon_t *create_laser_gun(res_t *res)
{
    weapon_t *weapon = malloc(sizeof(weapon_t));

    weapon->name = strdup("laser gun");
    weapon->shoot = &laser_gun_shoot;
    weapon->dmg = 15;
    weapon->lvl = 1;
    weapon->sprite = sfSprite_create();
    weapon->angle_offset = 0;
    weapon->fire_rate = 1.5;
    weapon->spray = 0;
    weapon->clock = sfClock_create();
    weapon->texture = res->weapons->laser_gun;
    sfSprite_setTexture(weapon->sprite, res->weapons->laser_gun, 0);
    sfSprite_setScale(weapon->sprite, (sfVector2f){2.5, 2.5});
    sfSprite_setOrigin(weapon->sprite, (sfVector2f){14, 6});
    return weapon;
}
