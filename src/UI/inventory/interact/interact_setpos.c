/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** interact_setpos
*/

#include "interact.h"

void interact_menu_setpos(interact_t *menu, sfVector2f pos)
{
    pos.y = ((pos.y + INTERACT_MENU_SIZE_Y) > E_MAX_Y) ? pos.y + (E_MAX_Y -
    (pos.y + INTERACT_MENU_SIZE_Y)) : pos.y;
    sfRectangleShape_setPosition(menu->background, pos);
    button_setposition(menu->EquipMainhand, (sfVector2f){pos.x +
    E_MAINHAND_OFFSET_X, pos.y + E_MAINHAND_OFFSET_Y});
    button_setposition(menu->EquipOffhand, (sfVector2f){pos.x +
    E_MAINHAND_OFFSET_X, pos.y + E_OFFHAND_OFFSET_Y});
    button_setposition(menu->delete, (sfVector2f){pos.x +
    E_MAINHAND_OFFSET_X, pos.y + E_DELETE_OFFSET_Y});
    button_setposition(menu->sell, (sfVector2f){pos.x +
    E_MAINHAND_OFFSET_X, pos.y + E_SELL_OFFSET_Y});
    button_setposition(menu->merge, (sfVector2f){pos.x +
    E_MAINHAND_OFFSET_X, pos.y + E_MERGE_OFFSET_Y});
    sfText_setPosition(menu->itemname, (sfVector2f){pos.x +
    E_TEXT_OFFSET_X, pos.y + E_TEXT_OFFSET_Y});
}
