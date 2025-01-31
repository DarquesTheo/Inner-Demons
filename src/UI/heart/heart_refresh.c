/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** heart_refresh
*/

#include "heart.h"
#include "game.h"
#include "player.h"

static void choose_heart(sfSprite *sprite, int hp, res_t *res)
{
    if (hp <= 0) {
            sfSprite_setTexture(sprite, res->inv->heart_empty, 0);
        }
        if (hp >= HEALTH_PER_HEART_QUARTER * 4) {
            sfSprite_setTexture(sprite, res->inv->heart_full, 0);
        }
        if (hp == HEALTH_PER_HEART_QUARTER * 3) {
            sfSprite_setTexture(sprite, res->inv->heart_three, 0);
        }
        if (hp == HEALTH_PER_HEART_QUARTER * 2) {
            sfSprite_setTexture(sprite, res->inv->heart_semi, 0);
        }
        if (hp == HEALTH_PER_HEART_QUARTER * 1) {
            sfSprite_setTexture(sprite, res->inv->heart_quarter, 0);
        }
}

void heart_refresh(heart_t *heart, game_t *game)
{
    int pool = game->player->hp;

    for (int i = 0; i < heart->heart_nb; i++) {
        choose_heart(heart->heart[i], pool, game->res);
        pool -= 1;
    }
}
