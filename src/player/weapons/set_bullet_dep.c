/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** set_bullet_dep
*/

#include "player.h"
#include "const.h"
#include <math.h>
#include "vector.h"
#include "anim.h"
#include <stdlib.h>
#include "artefact.h"

void set_bullet_dep(game_t *game, weapon_t *wp, anim_t *anim)
{
    sfVector2f wp_pos = sfSprite_getPosition(wp->sprite);
    sfVector2f dep = normalize_vector
    (get_vector_difference(wp_pos, game->info->mouse_pos));
    float spray = (float)(wp->spray) / get_multiplicator_stat(ACCURACY, game);
    float angle;
    float rad;

    if (wp->spray != 0) {
        angle = rand() % (int)(spray * 2) - spray;
        rad = angle * PI / 180;
        dep.x = dep.x * cos(rad) - dep.y * sin(rad);
        dep.y = dep.x * sin(rad) + dep.y * cos(rad);
        dep = normalize_vector(dep);
    }
    anim->move = mult_vector(dep, anim->speed);
    sfSprite_setRotation(anim->sprite,
    atan2(anim->move.y, anim->move.x) / PI * 180);
}
