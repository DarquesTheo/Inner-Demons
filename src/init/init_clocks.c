/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-baptiste.camerlynck
** File description:
** init_clocks
*/

#include "clock.h"
#include <stdlib.h>

clocks_t *init_clocks(void)
{
    clocks_t *clocks = malloc(sizeof(clocks_t));

    clocks->fps = sfClock_create();
    clocks->player_anim = sfClock_create();
    clocks->player_dash_smoke = sfClock_create();
    clocks->player_dash = sfClock_create();
    return clocks;
}
