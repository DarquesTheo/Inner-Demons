/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** is_button_pressed
*/

#include "button.h"

sfBool is_button_pressed(button_t *button, sfVector2f pos)
{
    sfVector2f mouse_pos = pos;

    if (is_in_rectangle(button->rect, mouse_pos)) {
        button->state = PRESSED;
        return sfTrue;
    }
    button->state = NONE;
    return sfFalse;
}
