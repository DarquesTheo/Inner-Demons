/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** on_each_fps_vertex
*/

#include "game.h"
#include "res.h"
#include "map.h"
#include "objects.h"

void on_each_fps_vertex(game_t *game)
{
    sfRenderStates render_state = sfRenderStates_default();

    render_state.texture = game->info->current_tileset;
    render_state.blendMode = sfBlendAlpha;
    sfTransform_scale(&(render_state.transform),
    game->map->scale.x, game->map->scale.y);
    sfTransform_translate(&(render_state.transform),
    game->map->transform.x, game->map->transform.y);
    sfRenderWindow_drawVertexArray(game->window,
    game->map->layer1, &render_state);
    sfRenderWindow_drawVertexArray(game->window,
    game->map->layer2, &render_state);
}

void on_each_fps_room(game_t *game)
{
    on_each_fps_vertex(game);
    for (pot_t *tmp = game->map->objects->pots; tmp; tmp = tmp->next) {
        sfRenderWindow_drawSprite(game->window, tmp->sprite, NULL);
        if (game->info->debug)
            sfRenderWindow_drawRectangleShape
            (game->window, tmp->hitbox->rect, NULL);
    }
    for (spike_t *tmp = game->map->objects->spikes; tmp; tmp = tmp->next) {
        sfRenderWindow_drawSprite(game->window, tmp->sprite, NULL);
        if (game->info->debug)
            sfRenderWindow_drawRectangleShape
            (game->window, tmp->hitbox->rect, NULL);
        animate_spike(game, tmp);
    }
}
