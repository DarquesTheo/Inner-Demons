/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** def_anim
*/

#include "player.h"
#include "anim.h"
#include "utils.h"
#include <stdlib.h>

void get_default_anim2(anim_t *anim)
{
    anim->go_to_player = sfFalse;
    anim->text = sfText_create();
    anim->type = ANIM_NONE;
    anim->layer = 1;
    anim->color = malloc(sizeof(anim_color_t));
    anim->color->color_clock = sfClock_create();
    anim->color->cadency = -1;
    anim->color->alpha_decrease = 0;
}

anim_t *get_default_anim(void)
{
    anim_t *anim = malloc(sizeof(anim_t));

    anim->sprite = sfSprite_create();
    anim->clock = sfClock_create();
    anim->dmg = 0;
    anim->time_count = 0;
    anim->duration = -1;
    anim->fps = -1;
    anim->img_width = -1;
    anim->loop = sfFalse;
    anim->move = v2f(0, 0);
    anim->on_collide = NULL;
    anim->rect = init_intrect(0, 0);
    anim->col = get_default_col();
    anim->hitbox = NULL;
    anim->nb_hit = 1;
    anim->speed = 0;
    anim->wp = NULL;
    get_default_anim2(anim);
    return anim;
}
