/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** init_mouse_input
*/

#include "keybinds.h"
#include <stdlib.h>

mouse_input_t *init_mouse_input(void)
{
    mouse_input_t *inputs = malloc(sizeof(mouse_input_t));

    inputs->left_click = 0;
    inputs->right_click = 0;
    return inputs;
}
