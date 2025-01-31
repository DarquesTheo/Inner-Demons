/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** utils
*/

#include "game.h"
#include "player.h"

//return if a point in a rectangle is on top, bottom, left or right
int get_point_pos_in_rectangle(sfVector2f p, sfVector2f rect_size)
{
    float y1 = rect_size.y * p.x / rect_size.x;
    float y2 = rect_size.y - y1;

    if (p.x < 0 || rect_size.x <= p.x || p.y < 0 || rect_size.y <= p.y)
        return OUT;
    else if (p.y < y1)
        return (p.y < y2) ? TOP : RIGHT;
    else
        return (p.y < y2) ? LEFT : BOTTOM;
}
