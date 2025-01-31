/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** slider_pressed
*/

#include "slider.h"

/* Make sure the pos is in the slider before */

void slider_pressed(slider_t *slider, sfVector2f pos)
{
    float value = 0.0;
    sfVector2f sliderpos = sfRectangleShape_getPosition(slider->rect);
    sfVector2f slidersize = sfRectangleShape_getSize(slider->rect);
    float cursorpos;

    pos.x -= sliderpos.x;
    value = pos.x / slidersize.x;
    slider->value = value;
    cursorpos = (sliderpos.x + (slidersize.x * value));
    cursorpos = (cursorpos >= sliderpos.x + slidersize.x) ?
        cursorpos - 8 : cursorpos;
    sfRectangleShape_setPosition(slider->cursor,
        (sfVector2f){cursorpos, sliderpos.y});
}
