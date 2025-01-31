/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** create_hitmarker
*/

#include "anim.h"
#include "utils.h"
#include <stdlib.h>
#include "res.h"
#include "utils.h"
#include "math.h"
#include "const.h"
#include "vector.h"

void set_hitmarker_dep(anim_t *anim, sfVector2f pos)
{
    int r = rand() % 360;
    float a = r * PI / 180;
    sfVector2f dep = v2f(cos(a), sin(a));
    sfVector2f tpos = add_vectors(pos, mult_vector(dep, 20));

    anim->move = mult_vector(dep, HITMARKER_SPEED);
    sfText_setPosition(anim->text, tpos);
}

anim_t *get_hitmarker(int dmg, sfVector2f pos, res_t *res, sfBool crit)
{
    anim_t *anim = get_default_anim();
    char *str = my_atoi(dmg);

    anim->type = ANIM_HIT;
    anim->layer = 2;
    anim->color->alpha_decrease = 13;
    anim->color->cadency = 20;
    sfText_setString(anim->text, str);
    sfText_setFont(anim->text, res->fonts->dialogue_font);
    sfText_setOutlineColor(anim->text, sfBlack);
    sfText_setOutlineThickness(anim->text, 3);
    if (crit)
        sfText_setFillColor(anim->text, sfRed);
    anim->duration = 1.5;
    set_hitmarker_dep(anim, pos);
    free(str);
    return anim;
}
