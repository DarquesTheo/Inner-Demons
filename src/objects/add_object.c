/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** add_object
*/

#include "anim.h"
#include "objects.h"
#include <string.h>
#include "res.h"
#include "utils.h"
#include "vector.h"
#include "const.h"
#include "sound_manager.h"

static void col_anim(game_t *game, sfVector2f pos)
{
    anim_t *anim = get_default_anim();

    anim->fps = 12;
    anim->img_width = 256;
    anim->duration = -1;
    anim->loop = sfFalse;
    sfSprite_setTexture(anim->sprite,
    game->res->obj_res->pot_explosion, 0);
    sfSprite_setOrigin(anim->sprite, (sfVector2f){32, 32});
    sfSprite_setPosition(anim->sprite, pos);
    sfSprite_setScale(anim->sprite, (sfVector2f){4, 4});
    anim->rect = init_intrect(64, 64);
    sfSprite_setTextureRect(anim->sprite, anim->rect);
    sfSprite_setRotation(anim->sprite, rand() % 360);
    add_anim(game, anim);
}

int obj_on_collide(game_t *game, anim_t *ani, UNUSED mob_t *mob,
    UNUSED col_type_t type)
{
    sfVector2f pos = sfSprite_getPosition(ani->sprite);

    if (!strcmp(ani->col->sfx, "pot"))
        pos = add_vectors(pos, v2f(40, -40));
    else
        pos = add_vectors(pos, v2f(40, -40));
    if (ani->rect.left == 0) {
        ani->rect.left = 32;
        spawn_random_money_radius(game, pos, 35, rand_int(1, 3));
        play_sound(game, ani->col->sfx, rand_float(0.8, 1.3));
        sfSprite_setTextureRect(ani->sprite, ani->rect);
        col_anim(game, pos);
        return 1;
    }
    return 0;
}

void set_obj_params(anim_t *anim, char *name, sfVector2f pos)
{
    if (!strcmp(name, "candle") || !strcmp(name, "dcandle")
    || !strcmp(name, "torch")) {
        anim->fps = rand_int(4, 6);
        anim->img_width = 64;
        return;
    }
    anim->img_width = 48;
    if (!strcmp(name, "pot")) {
        sfSprite_setOrigin(anim->sprite, v2f(0, 32));
        anim->hitbox = create_rect_hitbox(v2f(16 * 5, 16 * 5), v2f(40, -40));
    } else {
        sfSprite_setOrigin(anim->sprite, v2f(0, 16));
        anim->hitbox = create_rect_hitbox(v2f(16 * 5, 16 * 5), v2f(40, 40));
    }
    sfSprite_setPosition(anim->sprite, pos);
    place_sprite_hitbox(anim->hitbox, anim->sprite);
    anim->col->player_proj = sfTrue;
    anim->on_collide = &obj_on_collide;
}

void add_object(game_t *game, char *name, sfVector2f pos)
{
    anim_t *anim = get_default_anim();

    anim->col->sfx = strdup(name);
    anim->loop = sfTrue;
    sfSprite_setTexture(anim->sprite, get_tex(game, name), 0);
    sfSprite_setScale(anim->sprite, v2f(5, 5));
    anim->rect = init_intrect(16, 32);
    sfSprite_setTextureRect(anim->sprite, anim->rect);
    set_obj_params(anim, name, pos);
    anim->type = ANIM_OBJ;
    anim_y_sort_add(&(game->anims), anim);
}
