/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** button_create
*/

#include "button.h"

button_color_t *button_color_create(void)
{
    button_color_t *button_color = malloc(sizeof(button_color_t));

    button_color->c_default = sfWhite;
    button_color->c_hover = sfWhite;
    button_color->c_pressed = sfWhite;
    return button_color;
}

button_t *button_create(void)
{
    button_t *btn = malloc(sizeof(button_t));

    btn->is_clicked = &is_button_pressed;
    btn->is_hover = &is_button_hover;
    btn->visible = sfTrue;
    btn->state = NONE;
    btn->rect = sfRectangleShape_create();
    btn->icon = sfRectangleShape_create();
    btn->color = button_color_create();
    sfRectangleShape_setFillColor(btn->icon, sfTransparent);
    return btn;
}

button_color_t *button_color_create_default(void)
{
    button_color_t *color = button_color_create();

    color->c_default = sfCyan;
    color->c_hover = sfBlue;
    color->c_pressed = sfBlue;
    return color;
}

button_t *button_create_default(void)
{
    button_t *btn = button_create();

    button_setsize(btn, (sfVector2f){50, 50});
    btn->color = button_color_create_default();
    button_setfillcolor(btn, btn->color->c_default);
    return btn;
}
