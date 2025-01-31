/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** tornado
*/

#include "game.h"
#include "utils.h"
#include "vector.h"
#include "res.h"
#include "player.h"
#include "anim.h"
#include <string.h>
#include "const.h"
#include <stdlib.h>
#include "artefact.h"

int on_tornado_col(game_t *game, anim_t *ani, UNUSED mob_t *mob,
    col_type_t type)
{
    anim_t *anim = get_default_anim();
    sfVector2f pos = sfSprite_getPosition(ani->sprite);

    if (mob && type == COL_ENEMY)
        enemy_take_dmg(game, mob, ani->dmg);
    anim->fps = 12;
    anim->img_width = 576;
    anim->time_count = 0;
    anim->duration = -1;
    anim->loop = sfFalse;
    sfSprite_setTexture(anim->sprite,
    game->res->weapons->tornado_col, 0);
    sfSprite_setOrigin(anim->sprite, (sfVector2f){32, 45});
    sfSprite_setPosition(anim->sprite, pos);
    sfSprite_setScale(anim->sprite, (sfVector2f){4, 4});
    anim->rect = init_intrect(64, 64);
    sfSprite_setTextureRect(anim->sprite, anim->rect);
    anim->move = v2f(0.0f, 0.0f);
    add_anim(game, anim);
    return 1;
}

void staff_bullet2(game_t *game, anim_t *anim)
{
    anim->hitbox = create_rect_hitbox(v2f(100, 100), v2f(0, 0));
    place_sprite_hitbox(anim->hitbox, anim->sprite);
    anim->col->map = sfTrue;
    anim->col->ennemy = sfTrue;
    anim->col->object = sfTrue;
    add_anim(game, anim);
}

void staff_bullet(game_t *game, sfVector2f pos,
    sfVector2f move, weapon_t *wp)
{
    anim_t *anim = get_default_anim();

    anim->type = ANIM_PPROJ;
    anim->dmg = wp->dmg;
    anim->clock = sfClock_create();
    anim->fps = 5;
    anim->img_width = 160;
    anim->duration = 1.5;
    anim->loop = sfTrue;
    anim->sprite = sfSprite_create();
    anim->on_collide = &on_tornado_col;
    sfSprite_setTexture(anim->sprite,
    game->res->weapons->wind_staff_bullet, 0);
    sfSprite_setOrigin(anim->sprite, (sfVector2f){16, 16});
    sfSprite_setPosition(anim->sprite, pos);
    sfSprite_setScale(anim->sprite, (sfVector2f){5, 5});
    anim->rect = init_intrect(32, 31);
    sfSprite_setTextureRect(anim->sprite, anim->rect);
    anim->move = move;
    staff_bullet2(game, anim);
}

void wind_staff_shoot(game_t *game, weapon_t *wp)
{
    sfVector2f player_pos = sfSprite_getPosition(game->player->sprite);
    float speed = 500;
    sfVector2f dep = mult_vector(normalize_vector
    (get_vector_difference(player_pos, game->info->mouse_pos)), speed);
    sfVector2f muzzlepos = get_muzzle_pos(wp->sprite, v2f(36, 10));

    if ((rand() % 100) + 1 <=
    (get_multiplicator_stat(DOUBLE_SHOT, game) - 1) * 100) {
        muzzlepos.y += 60;
        staff_bullet(game, get_bullet_spawn(wp->sprite, muzzlepos), dep, wp);
        muzzlepos.y -= 120;
    }
    staff_bullet(game, get_bullet_spawn(wp->sprite, muzzlepos), dep, wp);
}

weapon_t *create_wind_staff(res_t *res)
{
    weapon_t *weapon = malloc(sizeof(weapon_t));

    weapon->name = strdup("wind staff");
    weapon->shoot = &wind_staff_shoot;
    weapon->dmg = 4;
    weapon->lvl = 1;
    weapon->sprite = sfSprite_create();
    weapon->angle_offset = 0;
    weapon->clock = sfClock_create();
    weapon->fire_rate = 2;
    weapon->texture = res->weapons->wind_staff;
    sfSprite_setTexture(weapon->sprite, res->weapons->wind_staff, 0);
    sfSprite_setScale(weapon->sprite, (sfVector2f){3, 3});
    sfSprite_setOrigin(weapon->sprite, (sfVector2f){8, 10});
    return weapon;
}
