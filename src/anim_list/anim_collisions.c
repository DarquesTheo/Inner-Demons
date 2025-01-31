/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** anim_list
*/

#include "game.h"
#include "vector.h"
#include "anim.h"
#include "vector.h"
#include "utils.h"
#include "map.h"

int get_tile_point_col(game_t *game, sfVector2f pos)
{
    sfVector2i tile = get_pos_tile(game->map, pos);

    if (tile.x < 0 || tile.y < 0)
        return 1;
    if (tile.x > game->map->size.x * game->map->tilesize.x
    || tile.y > game->map->size.y * game->map->tilesize.y)
        return 1;
    return game->map->collisions[tile.x + tile.y * game->map->size.x];
}

int are_rect_colliding(sfRectangleShape *r1, sfRectangleShape *r2)
{
    sfFloatRect fr1;
    sfFloatRect fr2;

    if (!r1 || !r2)
        return 0;
    fr1 = sfRectangleShape_getGlobalBounds(r1);
    fr2 = sfRectangleShape_getGlobalBounds(r2);
    return sfFloatRect_intersects(&fr1, &fr2, NULL);
}

int are_hitbox_colliding(hitbox_rect_t *h1, hitbox_rect_t *h2)
{
    if (!h1 || !h2)
        return 0;
    return are_rect_colliding(h1->rect, h2->rect);
}
