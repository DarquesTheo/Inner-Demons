/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** init_heart
*/

#include "heart.h"
#include "res.h"
#include "stdlib.h"

static void init_a_heart(sfSprite *heart, res_t *res, int i)
{
    sfSprite_setTexture(heart, res->inv->heart_full, 0);
    sfSprite_setPosition(heart, (sfVector2f){HEART_POS_X + (i * HEART_OFFSET_X)
    , HEART_POS_Y});
    sfSprite_setScale(heart, (sfVector2f){HEART_SCALE, HEART_SCALE});
}

heart_t *init_heart(res_t *res, int max_health)
{
    heart_t *heart = malloc(sizeof(heart_t));

    heart->healh_max = max_health;
    heart->heart_nb = (max_health / HEALTH_PER_HEART_QUARTER) / 4;
    heart->visible = sfTrue;
    heart->heart = malloc(sizeof(sfSprite *) * (heart->heart_nb + 1));
    for (int i = 0; i < heart->heart_nb; i++) {
        heart->heart[i] = sfSprite_create();
        sfSprite_setTexture(heart->heart[i], res->inv->heart_full, 0);
        init_a_heart(heart->heart[i], res, i);
    }
    return heart;
}
