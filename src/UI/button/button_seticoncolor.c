/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** button_seticoncolor
*/

#include "button.h"

void button_seticoncolor(button_t *button, sfColor color)
{
    sfRectangleShape_setFillColor(button->icon, color);
}
