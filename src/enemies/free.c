/*
** EPITECH PROJECT, 2024
** free.c
** File description:
** free functions
*/

#include "enemies.h"
#include "map.h"
#include "hitbox.h"
#include <stdlib.h>

void free_mob_res(res_mob_t *res)
{
    sfTexture_destroy(res->texture_attack2_boss1);
    sfTexture_destroy(res->texture_attack2_boss2);
    sfTexture_destroy(res->texture_cast_boss1);
    sfTexture_destroy(res->texture_spawn);
    for (int i = 0; i < I_MAX_ENEMIES; i++) {
        sfTexture_destroy(res->textures_attack[i]);
        sfTexture_destroy(res->textures_move[i]);
        sfTexture_destroy(res->textures_die[i]);
    }
    free(res);
}

void free_all_mobs(game_t *game)
{
    for (mob_t *node = game->map->mobs; node != NULL;) {
        free_mob(&node, &(game->map->mobs));
        node = game->map->mobs;
    }
}

void free_mob2(mob_t *mob)
{
    free(mob->pattern);
    sfRectangleShape_destroy(mob->hitbox->rect);
    free(mob->hitbox);
    free(mob->stats);
}

void free_mob(mob_t **mob_node, mob_t **list)
{
    mob_t *mob = *mob_node;

    sfClock_destroy(mob->pattern->clock_move);
    sfClock_destroy(mob->pattern->clock_shot);
    free_mob2(mob);
    sfSprite_destroy(mob->sprite_spawn);
    sfSprite_destroy(mob->sprite);
    sfClock_destroy(mob->clock_anim);
    sfClock_destroy(mob->clock_move);
    free(mob->projectile);
    if (mob->prev != NULL)
        mob->prev->next = mob->next;
    else
        *list = mob->next;
    if (mob->next != NULL)
        mob->next->prev = mob->prev;
    *mob_node = mob->next;
    free(mob);
}
