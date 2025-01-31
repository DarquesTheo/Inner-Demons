/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** menu_btn
*/

#include "button.h"

menu_btn_t *add_menu_btn(menu_btn_t *menu_btn, button_t *button)
{
    menu_btn_t *tmp = malloc(sizeof(menu_btn_t));

    tmp->button = button;
    tmp->next = menu_btn;
    return tmp;
}
