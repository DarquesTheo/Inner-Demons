/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** button_setposition
*/

#include "button.h"

void button_setposition(button_t *button, sfVector2f pos)
{
    sfRectangleShape_setPosition(button->rect, pos);
    sfRectangleShape_setPosition(button->icon, pos);
}
