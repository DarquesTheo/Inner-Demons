/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** sfrenderwindow_drawslider
*/

#include "slider.h"

void sfrenderwindow_drawslider(sfRenderWindow *window, slider_t *slider)
{
    sfRenderWindow_drawRectangleShape(window, slider->rect, NULL);
    sfRenderWindow_drawRectangleShape(window, slider->cursor, NULL);
}
