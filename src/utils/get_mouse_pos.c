/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** get_mouse_pos
*/

#include "game.h"

sfVector2f get_mouse_pos(sfRenderWindow *window)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(window);

    return (sfVector2f){pos.x, pos.y};
}
