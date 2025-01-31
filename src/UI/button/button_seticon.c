/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** button_seticon
*/

#include "button.h"

void button_seticon(button_t *button, sfTexture *texture)
{
    sfRectangleShape_setTexture(button->icon, texture, sfFalse);
    sfRectangleShape_setFillColor(button->icon, sfBlack);
}
