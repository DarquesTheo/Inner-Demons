/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** smg
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

int on_smg_col(game_t *game, anim_t *ani, UNUSED mob_t *mob, col_type_t type)
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
    sfSprite_setScale(anim->sprite, (sfVector2f){0.5, 0.5});
    anim->rect = init_intrect(64, 64);
    sfSprite_setTextureRect(anim->sprite, anim->rect);
    anim->move = v2f(0.0f, 0.0f);
    sfSprite_setRotation(anim->sprite, rand() % 360);
    add_anim(game, anim);
    return 1;
}

static void smg_bullet2(game_t *game, anim_t *anim)
{
    anim->rect = init_intrect(7, 7);
    anim->rect.left = (rand() % 5) * 7;
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

static void smg_bullet(game_t *game, sfVector2f muzzlepos, weapon_t *wp)
{
    anim_t *anim = get_default_anim();

    anim->type = ANIM_PPROJ;
    anim->dmg = wp->dmg * wp->lvl;
    anim->speed = 2000;
    set_bullet_dep(game, wp, anim);
    anim->fps = 20;
    anim->img_width = 35;
    anim->time_count = 0;
    anim->duration = 2;
    anim->loop = sfTrue;
    anim->on_collide = &on_smg_col;
    sfSprite_setTexture(anim->sprite,
    game->res->weapons->smg_bullet, 0);
    sfSprite_setOrigin(anim->sprite, (sfVector2f){3.5, 3.5});
    sfSprite_setPosition(anim->sprite, muzzlepos);
    sfSprite_setScale(anim->sprite, (sfVector2f){1.5, 1.5});
    smg_bullet2(game, anim);
}

void smg_shoot(game_t *game, weapon_t *wp)
{
    sfVector2f muzzlepos = get_muzzle_pos(wp->sprite, v2f(77, 10));

    if ((rand() % 100) + 1 <=
    (get_multiplicator_stat(DOUBLE_SHOT, game) - 1) * 100) {
        muzzlepos.y += 5;
        smg_bullet(game, get_bullet_spawn(wp->sprite, muzzlepos), wp);
        muzzlepos.y -= 10;
    }
    play_sound(game, "smg_shoot1", rand_float(0.7, 1));
    smg_bullet(game, get_bullet_spawn(wp->sprite, muzzlepos), wp);
}

weapon_t *create_smg(res_t *res)
{
    weapon_t *weapon = malloc(sizeof(weapon_t));

    weapon->name = strdup("smg");
    weapon->shoot = &smg_shoot;
    weapon->dmg = 3;
    weapon->lvl = 1;
    weapon->sprite = sfSprite_create();
    weapon->angle_offset = 0;
    weapon->fire_rate = 14;
    weapon->spray = 14;
    weapon->clock = sfClock_create();
    weapon->texture = res->weapons->smg;
    sfSprite_setTexture(weapon->sprite, res->weapons->smg, 0);
    sfSprite_setScale(weapon->sprite, (sfVector2f){1.25, 1.25});
    sfSprite_setOrigin(weapon->sprite, (sfVector2f){34, 18});
    return weapon;
}
