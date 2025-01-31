/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** on_each_fps_anim_list
*/

#include "game.h"
#include "anim.h"
#include "vector.h"

static void oef_anim_list2(game_t *game, float delta, anim_t *tmp)
{
    sfRenderWindow_drawSprite(game->window, tmp->sprite, NULL);
    sfRenderWindow_drawText(game->window, tmp->text, NULL);
    if (tmp->hitbox != NULL && game->info->debug)
        sfRenderWindow_drawRectangleShape(game->window,
        tmp->hitbox->rect, NULL);
    if (tmp->move.x != 0 || tmp->move.y != 0) {
        sfSprite_move(tmp->sprite, mult_vector(tmp->move, delta));
        sfText_move(tmp->text, mult_vector(tmp->move, delta));
        place_sprite_hitbox(tmp->hitbox, tmp->sprite);
    }
}

void on_each_fps_anim_list(game_t *game, float delta, int layer)
{
    for (anim_t *tmp = game->anims; tmp; tmp = tmp->next) {
        if (tmp->layer == layer) {
            oef_anim_list2(game, delta, tmp);
        }
    }
}
