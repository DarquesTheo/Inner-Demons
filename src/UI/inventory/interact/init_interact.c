/*
** EPITECH PROJECT, 2024
** rpg
** File description:
** init_interact
*/

#include "interact.h"
#include "res.h"

static void init_btn_icon(interact_t *menu, res_t *res)
{
    menu->sell = button_create_default();
    button_setsize(menu->sell, (sfVector2f){E_MAINHAND_SIZE_X,
    E_MAINHAND_SIZE_Y});
    button_setcallback(menu->sell, (void *)(void *)&sell);
    button_set_colors(menu->sell, sfTransparent, sfTransparent,
        sfTransparent);
    menu->merge = button_create_default();
    button_setsize(menu->merge, (sfVector2f){E_MAINHAND_SIZE_X,
    E_MAINHAND_SIZE_Y});
    button_setcallback(menu->merge, (void *)(void *)&merge);
    button_set_colors(menu->merge, sfTransparent, sfTransparent,
        sfTransparent);
    button_seticon(menu->EquipMainhand, res->inv->equip_left);
    button_seticon(menu->EquipOffhand, res->inv->equip_right);
    button_seticon(menu->delete, res->inv->delete);
    button_seticon(menu->sell, res->inv->sell);
    button_seticon(menu->merge, res->inv->merge);
    button_seticoncolor(menu->EquipMainhand, sfWhite);
    button_seticoncolor(menu->EquipOffhand, sfWhite);
    button_seticoncolor(menu->delete, sfWhite);
}

static void init_interact_btn(interact_t *menu, res_t *res)
{
    menu->EquipMainhand = button_create_default();
    button_setsize(menu->EquipMainhand, (sfVector2f){E_MAINHAND_SIZE_X,
    E_MAINHAND_SIZE_Y});
    button_setcallback(menu->EquipMainhand, (void *)(void *)&equip_mainhand);
    button_set_colors(menu->EquipMainhand, sfTransparent, sfTransparent,
        sfTransparent);
    menu->EquipOffhand = button_create_default();
    button_setsize(menu->EquipOffhand, (sfVector2f){E_MAINHAND_SIZE_X,
    E_MAINHAND_SIZE_Y});
    button_setcallback(menu->EquipOffhand, (void *)(void *)&equip_offhand);
    button_set_colors(menu->EquipOffhand, sfTransparent, sfTransparent,
        sfTransparent);
    menu->delete = button_create_default();
    button_setsize(menu->delete, (sfVector2f){E_MAINHAND_SIZE_X,
    E_MAINHAND_SIZE_Y});
    button_setcallback(menu->delete, (void *)(void *)&delete_interact);
    button_set_colors(menu->delete, sfTransparent, sfTransparent,
        sfTransparent);
    init_btn_icon(menu, res);
}

interact_t *init_interact_menu(res_t *res)
{
    interact_t *menu = malloc(sizeof(interact_t));

    menu->background = sfRectangleShape_create();
    sfRectangleShape_setSize(menu->background, (sfVector2f){
        INTERACT_MENU_SIZE_X, INTERACT_MENU_SIZE_Y});
    sfRectangleShape_setTexture(menu->background, res->inv->interactbg, 0);
    menu->visible = sfFalse;
    menu->locked = sfFalse;
    init_interact_btn(menu, res);
    button_seticoncolor(menu->sell, (sfColor){BLOCKED_BTN_COLOR});
    button_seticoncolor(menu->merge, (sfColor){BLOCKED_BTN_COLOR});
    menu->itemname = sfText_create();
    sfText_setFont(menu->itemname, res->inv->font);
    sfText_setCharacterSize(menu->itemname, 15);
    sfText_setString(menu->itemname, "empty");
    return menu;
}
