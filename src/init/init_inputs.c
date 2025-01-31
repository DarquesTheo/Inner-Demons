/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-baptiste.camerlynck
** File description:
** init_inputs
*/

#include "keybinds.h"
#include <stdlib.h>

inputs_t *init_inputs(void)
{
    inputs_t *inputs = malloc(sizeof(inputs_t));

    inputs->player_down = 0;
    inputs->player_left = 0;
    inputs->player_right = 0;
    inputs->player_up = 0;
    inputs->toggle_shop = 0;
    return inputs;
}
