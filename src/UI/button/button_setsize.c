/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** button_setsize
*/

#include "button.h"

void button_setsize(button_t *button, sfVector2f size)
{
    sfRectangleShape_setSize(button->rect, size);
    sfRectangleShape_setSize(button->icon, size);
}
