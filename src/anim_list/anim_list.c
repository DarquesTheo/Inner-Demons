/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** anim_list
*/

#include "game.h"
#include "vector.h"
#include "anim.h"
#include "player.h"
#include "system.h"
#include "objects.h"

static void anim_elem(anim_t *tmp, int *del)
{
    tmp->rect.left += tmp->rect.width;
    if (tmp->rect.left >= tmp->img_width) {
        tmp->rect.left = 0;
        if (!tmp->loop && tmp->duration == -1)
            *del = sfTrue;
    }
    sfSprite_setTextureRect(tmp->sprite, tmp->rect);
}

static void delete_cond(game_t *game, anim_t *tmp, float delta)
{
    if (tmp->duration != -1 &&
    (tmp->time_count >= tmp->duration || delta >= tmp->duration)) {
        if (tmp->on_collide != NULL)
            tmp->on_collide(game, tmp, NULL, COL_TIME);
        delete_anim(&(game->anims), tmp);
        return;
    }
}

static void anim_if_needed(game_t *game, anim_t *tmp)
{
    sfTime time = sfClock_getElapsedTime(tmp->clock);
    float delta = time.microseconds / 1000000.0;
    sfBool del = sfFalse;

    if (tmp->fps != -1) {
        if (delta * tmp->fps > 1) {
            sfClock_restart(tmp->clock);
            anim_elem(tmp, &del);
            tmp->time_count += delta;
        }
    }
    if (del == sfTrue) {
        return delete_anim(&(game->anims), tmp);
    }
    delete_cond(game, tmp, delta);
}

static void act_dep(game_t *game, anim_t *anim)
{
    sfVector2f pos;
    sfVector2f ppos;
    sfVector2f dep;

    if (anim->go_to_player == sfTrue && (game->system->statut == ENDING
    || game->system->statut == SHOPING)) {
        pos = sfSprite_getPosition(anim->sprite);
        ppos = sfSprite_getPosition(game->player->sprite);
        dep = normalize_vector(get_vector_difference(pos, ppos));
        dep = mult_vector(dep, COIN_SPEED);
        anim->move = dep;
    }
}

static void act_color2(anim_t *anim)
{
    sfColor tmp_color = sfText_getOutlineColor(anim->text);

    if (tmp_color.a - anim->color->alpha_decrease < 0)
        tmp_color.a = 0;
    else
        tmp_color.a -= anim->color->alpha_decrease;
    sfText_setOutlineColor(anim->text, tmp_color);
    tmp_color = sfText_getFillColor(anim->text);
    if (tmp_color.a - anim->color->alpha_decrease < 0)
        tmp_color.a = 0;
    else
        tmp_color.a -= anim->color->alpha_decrease;
    sfText_setFillColor(anim->text, tmp_color);
}

static void act_color(anim_t *anim)
{
    sfTime time = sfClock_getElapsedTime(anim->color->color_clock);
    float delta = time.microseconds / 1000000.0;
    sfColor tmp_color;

    if (delta * anim->color->cadency > 1) {
        sfClock_restart(anim->color->color_clock);
        tmp_color = sfSprite_getColor(anim->sprite);
        if (tmp_color.a - anim->color->alpha_decrease < 0)
            tmp_color.a = 0;
        else
            tmp_color.a -= anim->color->alpha_decrease;
        sfSprite_setColor(anim->sprite, tmp_color);
        act_color2(anim);
    }
}

void anim_list(game_t *game)
{
    anim_t *next_node = NULL;
    int anim_state = 0;

    for (anim_t *tmp = game->anims; tmp != NULL; tmp = next_node) {
        next_node = tmp->next;
        act_dep(game, tmp);
        act_color(tmp);
        anim_state = check_anim_col(game, tmp);
        if (anim_state == 1)
            continue;
        if (anim_state == 2) {
            return;
        }
        anim_if_needed(game, tmp);
    }
}
