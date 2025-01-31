/*
** EPITECH PROJECT, 2024
** B-MUL-200-TLS-2-1-myrpg-baptiste.camerlynck
** File description:
** init_keybinds
*/

#include "keybinds.h"
#include <stdlib.h>

keybinds_t *init_keybinds(void)
{
    keybinds_t *keybinds = malloc(sizeof(keybinds_t));

    keybinds->player_up = sfKeyZ;
    keybinds->player_down = sfKeyS;
    keybinds->player_left = sfKeyQ;
    keybinds->player_right = sfKeyD;
    keybinds->player_dash = sfKeySpace;
    keybinds->toggle_shop = sfKeyE;
    keybinds->toggle_inventory = sfKeyTab;
    return keybinds;
}
