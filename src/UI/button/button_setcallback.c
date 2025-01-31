/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** button_setcallback
*/

#include "button.h"

void button_setcallback(button_t *button, void (*callback_func)(void *))
{
    button->on_pressed = callback_func;
}
