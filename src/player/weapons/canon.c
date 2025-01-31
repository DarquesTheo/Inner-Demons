/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** canon
*/

#include "game.h"
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
#include "hitbox.h"
#include "artefact.h"

static void on_explosion_col2(game_t *game, UNUSED anim_t *ani,
    UNUSED mob_t *mob)
{
    anim_t *anim = get_default_anim();

    anim->fps = 20;
    anim->img_width = 448;
    anim->duration = -1;
    anim->loop = sfFalse;
    sfSprite_setTexture(anim->sprite, game->res->weapons->ak47_col, 0);
    sfSprite_setOrigin(anim->sprite, (sfVector2f){32, 32});
    sfSprite_setPosition(anim->sprite, sfSprite_getPosition(mob->sprite));
    sfSprite_setScale(anim->sprite, (sfVector2f){5, 5});
    anim->rect = init_intrect(64, 64);
    sfSprite_setTextureRect(anim->sprite, anim->rect);
    anim->move = v2f(0.0f, 0.0f);
    sfSprite_setRotation(anim->sprite, rand() % 360);
    add_anim(game, anim);
}

//take in count the linked list of hit
int on_explosion_col(game_t *game, anim_t *ani, UNUSED mob_t *mob,
    UNUSED col_type_t type)
{
    sfBool do_anim = sfFalse;

    if (!is_mob_in_hit_list(ani->col->hit_list, mob)) {
        enemy_take_dmg(game, mob, ani->dmg);
        add_mob_hit(&(ani->col->hit_list), mob);
        do_anim = sfTrue;
    }
    if ((!mob) || do_anim)
        on_explosion_col2(game, ani, mob);
    return 0;
}

static void on_canon_col2(game_t *game, anim_t *anim)
{
    anim->rect = init_intrect(32, 32);
    sfSprite_setTextureRect(anim->sprite, anim->rect);
    sfSprite_setRotation(anim->sprite, rand() % 360);
    sfRectangleShape_setRotation(anim->hitbox->rect,
    sfSprite_getRotation(anim->sprite));
    play_sound(game, "cannon_explosion", rand_float(0.5, 0.9));
}

int on_canon_col(game_t *game, anim_t *ani, UNUSED mob_t *mob,
    UNUSED col_type_t type)
{
    anim_t *anim = get_default_anim();

    anim->fps = 12;
    anim->img_width = 256;
    anim->dmg = ani->dmg;
    anim->on_collide = &on_explosion_col;
    anim->col->ennemy = sfTrue;
    sfSprite_setTexture(anim->sprite, get_tex(game, "canon_col"), 0);
    sfSprite_setOrigin(anim->sprite, (sfVector2f){16, 16});
    sfSprite_setPosition(anim->sprite, sfSprite_getPosition(ani->sprite));
    sfSprite_setScale(anim->sprite, (sfVector2f){12, 12});
    anim->hitbox = create_rect_hitbox(v2f(32 * 12, 32 * 12), v2f(0, 0));
    place_sprite_hitbox(anim->hitbox, anim->sprite);
    add_anim(game, anim);
    on_canon_col2(game, anim);
    return 1;
}

static void canon_bullet2(game_t *game, anim_t *anim)
{
    anim->rect = init_intrect(27, 16);
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

static void canon_bullet(game_t *game, sfVector2f muzzlepos,
    weapon_t *wp)
{
    anim_t *anim = get_default_anim();

    anim->type = ANIM_PPROJ;
    anim->dmg = wp->dmg * wp->lvl;
    anim->speed = 2000;
    set_bullet_dep(game, wp, anim);
    anim->fps = 10;
    anim->img_width = 108;
    anim->time_count = 0;
    anim->duration = 2;
    anim->loop = sfTrue;
    anim->on_collide = &on_canon_col;
    sfSprite_setTexture(anim->sprite, get_tex(game, "canon_bullet"), 0);
    sfSprite_setOrigin(anim->sprite, (sfVector2f){18, 8});
    sfSprite_setPosition(anim->sprite, muzzlepos);
    sfSprite_setScale(anim->sprite, (sfVector2f){3, 3});
    sfSprite_setRotation(anim->sprite,
    sfSprite_getRotation(wp->sprite));
    canon_bullet2(game, anim);
}

void canon_shoot(game_t *game, weapon_t *wp)
{
    sfVector2f muzzlepos = get_muzzle_pos(wp->sprite, v2f(28, 4));

    play_sound(game, "cannon_shoot", rand_float(0.8, 1.2));
    if ((rand() % 100) + 1 <=
    (get_multiplicator_stat(DOUBLE_SHOT, game) - 1) * 100) {
        muzzlepos.y += 20;
        canon_bullet(game, get_bullet_spawn(wp->sprite, muzzlepos), wp);
        muzzlepos.y -= -40;
    }
    canon_bullet(game, get_bullet_spawn(wp->sprite, muzzlepos), wp);
}

weapon_t *create_canon(game_t *game)
{
    weapon_t *weapon = malloc(sizeof(weapon_t));

    weapon->name = strdup("cannon");
    weapon->shoot = &canon_shoot;
    weapon->dmg = 40;
    weapon->lvl = 1;
    weapon->sprite = sfSprite_create();
    weapon->angle_offset = 0;
    weapon->fire_rate = 0.4;
    weapon->spray = 0;
    weapon->clock = sfClock_create();
    weapon->texture = get_tex(game, "canon");
    sfSprite_setTexture(weapon->sprite, get_tex(game, "canon"), 0);
    sfSprite_setScale(weapon->sprite, (sfVector2f){2.5, 2.5});
    sfSprite_setOrigin(weapon->sprite, (sfVector2f){14, 6});
    return weapon;
}
