/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** get_poipnt_side_in_rectangle
*/

#include "game.h"
#include "player.h"

int get_point_side_in_rectangle(sfVector2f p, sfVector2f rect_size)
{
    if (p.x > rect_size.x / 2)
        return RIGHT;
    else
        return LEFT;
}
