/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** is_slider_pressed
*/

/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** slider_create
*/

#include "slider.h"
#include "button.h"

sfBool is_slider_pressed(slider_t *slider, sfVector2f pos)
{
    return is_in_rectangle(slider->rect, pos);
}
