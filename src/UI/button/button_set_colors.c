/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** button_set_colors
*/

#include "button.h"

void button_set_colors(button_t *button, sfColor defaut, sfColor hover,
    sfColor pressed)
{
    button->color->c_default = defaut;
    button->color->c_hover = hover;
    button->color->c_pressed = pressed;
}
