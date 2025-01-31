/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** button_setfillcolor
*/

#include "button.h"

void button_setfillcolor(button_t *button, sfColor color)
{
    button->color->c_default = color;
    sfRectangleShape_setFillColor(button->rect, color);
}
