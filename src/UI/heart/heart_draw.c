/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** heart_draw
*/

#include "heart.h"

void sfrenderwindow_drawheart(sfRenderWindow *window, heart_t *heart)
{
    if (!heart->visible)
        return;
    for (int i = 0; i < heart->heart_nb; i++) {
        sfRenderWindow_drawSprite(window, heart->heart[i], NULL);
    }
}
