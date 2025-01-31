/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** slot_isempty
*/

#include "inventory.h"

sfBool slot_isempty(slot_t *slot)
{
    if (slot->content == NULL)
        return sfTrue;
    return sfFalse;
}
