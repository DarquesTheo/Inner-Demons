/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** slider_create
*/

#include "slider.h"
#include <stdlib.h>

slider_t *slider_create(void)
{
    slider_t *slider = malloc(sizeof(slider_t));

    slider->value = 0.0;
    slider->rect = sfRectangleShape_create();
    slider->cursor = sfRectangleShape_create();
    slider->visible = sfTrue;
    slider->is_clicked = &is_slider_pressed;
    slider->on_pressed = &slider_pressed;
    return slider;
}

slider_t *slider_create_default(void)
{
    slider_t *slider = slider_create();

    sfRectangleShape_setSize(slider->rect, (sfVector2f){400, 50});
    sfRectangleShape_setSize(slider->cursor, (sfVector2f){8, 50});
    sfRectangleShape_setFillColor(slider->rect, (sfColor){100, 100, 100, 255});
    sfRectangleShape_setFillColor(slider->cursor, sfWhite);
    return slider;
}
