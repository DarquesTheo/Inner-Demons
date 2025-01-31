/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** sfrenderwindow_drawbutton
*/

#include "button.h"

static void choose_color(button_t *button)
{
    switch (button->state) {
        case NONE:
            button_setfillcolor(button, button->color->c_default);
            break;
        case HOVER:
            button_setfillcolor(button, button->color->c_hover);
            break;
        case PRESSED:
            button_setfillcolor(button, button->color->c_pressed);
            break;
        case RELEASED:
            return;
        }
}

void sfrenderwindow_drawbutton(sfRenderWindow *window, button_t *button)
{
    choose_color(button);
    sfRenderWindow_drawRectangleShape(window, button->rect, NULL);
    sfRenderWindow_drawRectangleShape(window, button->icon, NULL);
}
