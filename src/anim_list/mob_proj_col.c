/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** mob_proj_col
*/

#include "game.h"
#include "anim.h"
#include "const.h"
#include "enemies.h"
#include "res.h"
#include "utils.h"

int mob_projcol(game_t *game, anim_t *ani, UNUSED mob_t *mob, col_type_t type)
{
    anim_t *anim = get_default_anim();
    sfVector2f pos = sfSprite_getPosition(ani->sprite);

    if (type == COL_PLAYER || type == COL_WALL)
    anim->fps = 20;
    anim->img_width = 1280;
    anim->loop = sfFalse;
    sfSprite_setTexture(anim->sprite,
    game->res->weapons->ak47_col, 0);
    sfSprite_setOrigin(anim->sprite, (sfVector2f){32, 32});
    sfSprite_setPosition(anim->sprite, pos);
    sfSprite_setScale(anim->sprite, (sfVector2f){1, 1});
    anim->rect = init_intrect(64, 64);
    sfSprite_setTextureRect(anim->sprite, anim->rect);
    sfSprite_setRotation(anim->sprite, rand() % 360);
    add_anim(game, anim);
    return 1;
}
