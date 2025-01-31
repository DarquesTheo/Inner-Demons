/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** get_weapon_icon
*/

#include "player.h"

sfTexture *get_weapon_icon(weapon_t *weapon)
{
    return weapon->texture;
}
