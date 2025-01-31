/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** slider_setposition
*/

#include "slider.h"

void slider_setposition(slider_t *slider, sfVector2f pos)
{
    sfRectangleShape_setPosition(slider->rect, pos);
    sfRectangleShape_setPosition(slider->cursor, pos);
}
