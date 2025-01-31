/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** is_in_rectangle
*/

#include "button.h"

sfBool is_in_rectangle(sfRectangleShape *rect, sfVector2f position)
{
    sfFloatRect bounds = sfRectangleShape_getGlobalBounds(rect);

    return sfFloatRect_contains(&bounds, position.x, position.y);
}
