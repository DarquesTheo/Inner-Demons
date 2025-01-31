/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** pot_on_collide
*/

#include "objects.h"
#include "anim.h"
#include "game.h"
#include "res.h"
#include "vector.h"
#include "utils.h"
#include <stdlib.h>
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
    anim->move = v2f(0.0f, 0.0f);
    sfSprite_setRotation(anim->sprite, rand() % 360);
    add_anim(game, anim);
}

void pot_on_collide(game_t *game, pot_t *pot)
{
    sfVector2f pos = sfSprite_getPosition(pot->sprite);

    pos = add_vectors(pos, v2f(5 * 8, 5* 8));
    if (pot->state == POT_INTACT) {
        pot->state = POT_DESTROYED;
        spawn_random_money(game, pos, 1);
        play_sound(game, "pot_break", rand_float(0.6, 1.3));
        pot->rect.left += 32;
        sfSprite_setTextureRect(pot->sprite, pot->rect);
        col_anim(game,
        add_vectors(sfSprite_getPosition(pot->sprite), v2f(32, 32)));
    }
}
