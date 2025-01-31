/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** slider_updatevalue
*/

#include "slider.h"

/* Value must be between 0 and 1 */

void slider_updatevalue(slider_t *slider, float value)
{
    sfVector2f sliderpos = sfRectangleShape_getPosition(slider->rect);
    sfVector2f slidersize = sfRectangleShape_getSize(slider->rect);

    if (value < 0 || value > 1)
        return;
    sfRectangleShape_setPosition(slider->cursor,
        (sfVector2f){sliderpos.x + (slidersize.x *value), sliderpos.y});
    slider->value = value;
}
