/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** hearth
*/

#ifndef HEART_H_
    #define HEART_H_

    #include "SFML/Graphics.h"
    #include "game.h"

    #define DEFAULT_MAX_HEALTH 5
    #define HEALTH_PER_HEART_QUARTER 0.25

    #define HEART_POS_X 100000 - 900
    #define HEART_POS_Y 100000 - 500
    #define HEART_OFFSET_X 60
    #define HEART_SCALE 4

typedef struct heart_s {
    sfSprite **heart;
    sfBool visible;
    int heart_nb;
    int healh_max;
} heart_t;

void sfrenderwindow_drawheart(sfRenderWindow *window, heart_t *heart);
void heart_refresh(heart_t *heart, game_t *game);
void heart_destroy(heart_t *heart);

#endif /* !HEARTH_H_ */
